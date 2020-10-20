#include "Core.h"
#ifdef STRATEGY
#include "Input.h"
#include "Event/Event.h"
#include "Strategy/pins.h"

namespace Inputs{
    Button checkListButton(PIN_BUTTON_CHECKLIST);
    Switch strategySwitch(PIN_SWITCH_STRATEGY);
    Switch teamSwitch(PIN_SWITCH_TEAM);
    Switch avoidanceSwitch(PIN_SWITCH_AVOIDANCE);

    void init(){
        checkListButton.init();
        strategySwitch.init();
        teamSwitch.init();
        avoidanceSwitch.init();
    }

    void update(){
        checkListButton.update();
        strategySwitch.update();
        teamSwitch.update();
        avoidanceSwitch.update();
    }

    void eventloop(){
        if( checkListButton.pressed() )
            Event::fire("checklistPressed");
        if( strategySwitch.changed() )
            Event::fire("strategySwitchChanged");
        if( teamSwitch.changed() )
            Event::fire("teamSwitchChanged");
        if( avoidanceSwitch.changed() )
            Event::fire("avoidanceSwitchChanged");
    }
}


#endif