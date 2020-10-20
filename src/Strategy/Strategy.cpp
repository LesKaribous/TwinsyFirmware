#include "Core.h"
#ifdef STRATEGY
//Core
#include "Planner/Planner.h"
#include "Request/Request.h"
#include "Event/Event.h"
//Strategy
#include "IHM/IHM.h"
 
using namespace Core;

//Init modules
void Core::init(){
    #ifdef DEBUG 
        Debugger::init(); //Warning blocking if no Serial is available
    #endif

    IHM::init();
    Planner::init();
    Request::init();
}


//Update modules
void Core::update(){
    Planner::exec();
    Request::update();
    IHM::update();

    eventloop();
}

//Acquire & stores events
void Core::eventloop(){
    IHM::eventloop();
    Request::eventloop();
    
    Event::flush();
}

#endif