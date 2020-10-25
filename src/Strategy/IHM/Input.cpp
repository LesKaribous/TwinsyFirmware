#include "Core.h"
#ifdef STRATEGY
#include "Input.h"
#include "Event/Event.h"
#include "Strategy/pins.h"

Switch Inputs::starter(PIN_STARTER_SENSOR);
Switch Inputs::jumperRobotType(PIN_JUMPER_TYPE);
AnalogButton Inputs::buttonChecklist(PIN_BUTTON_CHECKLIST); //inverted
DigitalInput Inputs::switchStrategy(PIN_SWITCH_STRATEGY);
DigitalInput Inputs::switchAvoidance(PIN_SWITCH_AVOIDANCE);
AnalogSwitch Inputs::switchTeam(PIN_SWITCH_TEAM);

void Inputs::init(){
    starter.init();
    jumperRobotType.init();
    buttonChecklist.init();
    switchAvoidance.init();
    switchTeam.init();
    switchStrategy.init();
    update();
}

//+100ms
void Inputs::update(){
    buttonChecklist.update();

}

void Inputs::eventloop(){


}



#endif