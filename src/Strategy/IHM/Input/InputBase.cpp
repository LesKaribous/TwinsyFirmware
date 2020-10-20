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

AnalogInput::AnalogInput(int pin, int threshold) : InputBase(pin, false){
    _threshold = threshold;
    _value = _pValue = 0;
}

void AnalogInput::update(){
    _pValue = _value;
    _value = analogRead(_pin);
}

bool AnalogInput::getDigitalState(){
    return (_value > _threshold);
}

int AnalogInput::getRawValue(){
    analogRead(_pin);
}

bool AnalogInput::changed(){
    return _value != _pValue;
}

int AnalogInput::getValue(){
    return _value;
}

//Digital Input (Use Pullup)
DigitalInput::DigitalInput(int pin, bool inverted) : InputBase(pin, true){
    _inverted = inverted;
    _state =_pState = _inverted;
}

void DigitalInput::update(){
    _pState = _state;
    _state = digitalRead(_pin);
}

bool DigitalInput::getState(){
    return _state != _inverted;
}

bool DigitalInput::isInverted(){
    return _inverted;
}

bool DigitalInput::changed(){
    return _state != _pState;
}

void DigitalInput::setInverted(bool state){
    _inverted = state;
}

#endif