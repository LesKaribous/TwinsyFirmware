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

void InputBase::update(){}

//Analog Input

AnalogInput::AnalogInput(int pin, int threshold) : InputBase(pin){
    _threshold = threshold;
}


bool AnalogInput::getDigitalState(){
    return analogRead(_pin) > 20;
}

int AnalogInput::getRawValue(){
    analogRead(_pin);
}

int AnalogInput::getValue(){
    analogRead(_pin);
}

//Digital Input (Use Pullup)
DigitalInput::DigitalInput(int pin, bool inverted) : InputBase(pin, true){
    _inverted = inverted;
    _pState = _inverted;
}

bool DigitalInput::getState(){
    return digitalRead(_pin) != _inverted;
}

bool DigitalInput::isInverted(){
    return _inverted;
}

bool DigitalInput::changed(){
    bool res = digitalRead(_pin) != _pState;
    _pState = digitalRead(_pin);
    return res;
}

void DigitalInput::setInverted(bool state){
    _inverted = state;
}

#endif