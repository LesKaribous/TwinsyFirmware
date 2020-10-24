#include "Core.h"
#ifdef STRATEGY
#include "Input.h"
#include "Event/Event.h"
#include "Strategy/pins.h"


AnalogButton Inputs::checkListButton(PIN_BUTTON_CHECKLIST); //inverted
DigitalInput Inputs::strategySwitch(PIN_SWITCH_STRATEGY);
DigitalInput Inputs::avoidanceSwitch(PIN_SWITCH_AVOIDANCE);
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

}

void Inputs::eventloop(){
    if(checkListButton.pressed()) Debugger::assert("Yep");
    else Debugger::assert("No");
}



#endif