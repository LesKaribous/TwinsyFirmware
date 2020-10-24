#include "Core.h"
#ifdef STRATEGY

#include "Switch.h"

AnalogSwitch::AnalogSwitch(int pin, bool inverted) : InputBase(pin, false){
    _inverted = inverted;
}


bool AnalogSwitch::getState(){
    int result = false;
    for(size_t i(0); i < SAMPLING_COUNT; i++){
        result += (analogRead(_pin) == 0) ? 1 : -1;
    }

    return (result > 0) != _inverted;
}

bool AnalogSwitch::getRawState(){
    return (analogRead(_pin) == 0) != _inverted;
}

bool AnalogSwitch::isInverted(){
    return _inverted;
}


#endif