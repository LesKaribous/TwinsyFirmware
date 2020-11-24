#include "Core.h"
#ifdef PILOT

#include "Planner/Planner.h"

namespace Core{
    void init(){
        Planner::init();
    }


    void update(){
        Planner::exec();
    }


    void stop(){
        
    }

    void emmergencyStop(){
        
    }
}
#endif