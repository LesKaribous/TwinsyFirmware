#include "Core.h"
#ifdef STRATEGY
//Core
#include "Planner/Planner.h"
#include "Request/Request.h"
//Strategy
#include "IHM/IHM.h"
#include "IHM/Menu.h"
 
using namespace Core;

//Init modules
void Core::init(){
    delay(2000);
    
    IHM::init();
    Debugger::init();
    if(!Debugger::enabled) Menu::focus(Menu::SETTINGS);

    Planner::init();
    Request::init();
}


//Update modules
void Core::update(){
    Planner::exec();
    Request::update();
    IHM::update();
}



#endif