#include "Core.h"
#ifdef STRATEGY
#include "InputBase.h"

//Input Base class

InputBase::InputBase(int pin, bool pullup){
    _pin = pin;
    _pullup = pullup;
}

void InputBase::init(){
    if(_pullup)
        pinMode(_pin, INPUT_PULLUP);
    else
        pinMode(_pin, INPUT);
}

//Analog Input

AnalogInput::AnalogInput(int pin) : InputBase(pin, false){}

int AnalogInput::getRawValue(){
    return analogRead(_pin);
}

int AnalogInput::getValue(){
    long result = 0;
    for (size_t i = 0; i < SAMPLING_COUNT; i++){
        result += analogRead(_pin);
    }
    return result / SAMPLING_COUNT;
}

//Digital Input (Use Pullup)
DigitalInput::DigitalInput(int pin, bool inverted) 
    : InputBase(pin, true), _inverted(inverted){}

bool DigitalInput::getState(){
    int result = false;
    for(size_t i(0); i < SAMPLING_COUNT; i++){
        result += digitalRead(_pin) ? 1 : -1;
    }

    return (result > 0) != _inverted;
}

bool DigitalInput::getRawState(){
    return digitalRead(_pin) != _inverted;
}

bool DigitalInput::isInverted(){
    return _inverted;
}


#endif