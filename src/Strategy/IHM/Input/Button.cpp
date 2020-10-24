#include "Core.h"
#include "Button.h"

Button::Button(int pin, bool inverted, long pressTimeout) 
: DigitalInput(pin, inverted), _pressTimeout(pressTimeout), _pState(inverted), _pressed(false){}

void Button::update(){
    bool state = getState();
    if(state != _pState){
        if(state != _inverted){
            _pressed = true;
            _pressedTime = millis();
        }else{
            _pressed = false;
            _pressedTime = infinityf();
        }
    }
    _pState = state;
}

bool Button::pressed(){
    return _pressed && (millis() - _pressedTime) > _pressTimeout;
}


//Analogbutton
AnalogButton::AnalogButton(int pin, bool inverted, int pressTimeout) 
: AnalogSwitch(pin, inverted), _pressTimeout(pressTimeout),_pressedTime(0), _pressed(false){}

void AnalogButton::update(){
    bool state = getState();
    if(state != _pState){
        if(state){
            _pressed = true;
            _pressedTime = millis();
        }else{
            _pressed = false;
            _pressedTime = infinityf();
        }
    }
    _pState = state;
}

bool AnalogButton::pressed(){
    return _pressed && (millis() - _pressedTime) > _pressTimeout;
}

