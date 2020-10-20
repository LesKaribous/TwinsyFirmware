#include "Core.h"
#include "Button.h"

Button::Button(int pin, long pressThresold, bool inverted) 
: DigitalInput(pin, inverted), _pressThresold(pressThresold){}

bool Button::pressed(){
    if (getState()){
        if(_pressedTime == 0) _pressedTime = millis();
        if(millis() - _pressedTime > _pressThresold) return true;
    }else{
        _pressedTime = 0;
    }
    return false;
}

AnalogButton::AnalogButton(int pin, long pressThreshold, bool inverted) 
: AnalogInput(pin), _pressThreshold(pressThreshold), _inverted(inverted){}

bool AnalogButton::pressed(){
    if (getDigitalState()){
        if(_pressedTime == 0) _pressedTime = millis();
        if(millis() - _pressedTime > _pressThreshold) return true;
    }else{
        _pressedTime = 0;
    }
    return false;
}