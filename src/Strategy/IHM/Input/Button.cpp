#include "Core.h"
#include "Button.h"

Button::Button(int pin, long pressTimeout, bool inverted) 
: DigitalInput(pin, inverted), _pressTimeout(pressTimeout), _pressed(false){}

void Button::update(){
    DigitalInput::update();
    if (changed() && !_pressed){
        if(getState()){
            if(_pressedTime == 0) _pressedTime = millis();
        }else{
            if(millis() - _pressedTime > _pressTimeout) _pressed = true;
            _pressedTime = 0;
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
}

//Analogbutton
AnalogButton::AnalogButton(int pin, long pressTimeout, int analogThreshold, bool inverted) 
: AnalogInput(pin, analogThreshold), _pressTimeout(pressTimeout),_pressedTime(0), _pressed(false), _inverted(inverted){}

void AnalogButton::update(){
    AnalogInput::update();
    if (changed() && !_pressed){
        if(getDigitalState()){
            if(_pressedTime == 0) _pressedTime = millis();
        }else{
            if(millis() - _pressedTime > _pressTimeout) _pressed = true;
            _pressedTime = 0;
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
}