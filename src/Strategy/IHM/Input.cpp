#include "Core.h"
#ifdef STRATEGY
#include "Input.h"
#include "Event/Event.h"
#include "Strategy/pins.h"


AnalogButton Inputs::checkListButton(PIN_BUTTON_CHECKLIST, true, 100); //inverted
Switch Inputs::strategySwitch(PIN_SWITCH_STRATEGY);
Switch Inputs::avoidanceSwitch(PIN_SWITCH_AVOIDANCE);
AnalogSwitch Inputs::teamSwitch(PIN_SWITCH_TEAM);

void Inputs::init(){
    checkListButton.init();
    strategySwitch.init();
    teamSwitch.init();
    avoidanceSwitch.init();

    update(); //Init stableState before event propagation
}

//+100ms
void Inputs::update(){
    checkListButton.update();
    strategySwitch.update();
    teamSwitch.update();
    avoidanceSwitch.update();
    delay(100);
}

void Inputs::eventloop(){
    
    if( checkListButton.pressed() )
        Event::fire("checklistPressed");
    if( strategySwitch.changed() )
        Event::fire("strategySwitchChanged");
    if( teamSwitch.changed() )
        Event::fire("teamSwitchChanged");
    if( avoidanceSwitch.changed() )
        Event::fire("avoidanceSwitchChanged");

}



#endif