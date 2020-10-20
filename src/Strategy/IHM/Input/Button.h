#pragma once
#include "InputBase.h"

class Button : public DigitalInput{
public :

    Button(int pin, long pressThreshold = 180, bool inverted = false);

    bool pressed();
    
private:
    const long _pressThresold;
    long _pressedTime;
};

class AnalogButton : public AnalogInput{

    AnalogButton(int pin, long pressThreshold = 20, bool inverted = false);
    bool pressed();

private:
    const long _pressThreshold;
    long _pressedTime;
    bool _inverted;

};
