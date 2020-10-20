#pragma once

#include "Core.h"
#include "InputBase.h"

typedef DigitalInput Switch;

class AnalogSwitch : public DigitalInput{
public :
    AnalogSwitch(int pin, bool inverted = false, int threshold = 20) 
    : DigitalInput(pin, inverted), _threshold(threshold){}

    void update(){
        _pState = _state;
        _state = analogRead(_pin) > _threshold;
    }

private:
    int _threshold;
};