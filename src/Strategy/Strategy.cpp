#include "Core.h"
#ifdef STRATEGY
//Core
#include "Planner/Planner.h"
#include "Request/Request.h"
#include "Event/Event.h"
//Strategy
#include "IHM/IHM.h"
 
namespace Core{
    //Init modules
    void init(){
        IHM::init();
        Planner::init();
        Request::init();
    }


    //Update modules
    void update(){
        Planner::exec();
        Request::update();
        IHM::update();
    }

    //Acquire & stores events
    void eventloop(){
        IHM::eventloop();
        Request::eventloop();
        
        Event::flush();
    }
}
#endif