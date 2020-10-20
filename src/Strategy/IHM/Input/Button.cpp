#include "Core.h"
#include "Button.h"

Button::Button(int pin, bool inverted, long pressTimeout) 
: DigitalInput(pin, inverted), _pressTimeout(pressTimeout), _pressed(false){}

void Button::update(){
    DigitalInput::update();
    if (changed()){
        if(getState()){
            _pressedTime = millis();
        }else{
            if(!_pressed && millis() - _pressedTime > _pressTimeout) _pressed = true;
        }
    }else{
        if(_pressed) release();
    }
}

bool Button::pressed(){
    return _pressed;
}

void Button::release(){
    _pressed = false;
    _pressedTime = 0;
}

//Analogbutton
AnalogButton::AnalogButton(int pin, bool inverted, int pressTimeout, int analogThreshold) 
: AnalogSwitch(pin, inverted, analogThreshold), _pressTimeout(pressTimeout),_pressedTime(0), _pressed(false){}

void AnalogButton::update(){
    AnalogSwitch::update();
    if (changed()){
        if(getState()){
            _pressedTime = millis();
        }else{
            if(!_pressed && millis() - _pressedTime > _pressTimeout) _pressed = true;
        }
    }else{
        if(_pressed) release();
    }
}

bool AnalogButton::pressed(){
    return _pressed;
}

void AnalogButton::release(){
    _pressed = false;
    _pressedTime = 0;
}