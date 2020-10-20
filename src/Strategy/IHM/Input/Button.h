#pragma once
#include "InputBase.h"
#include "Switch.h"

class Button : public DigitalInput{
public :
    Button(int pin, bool inverted = false, long pressTimeout = 180);

    void update();
    bool pressed();

    void release();
    
private:
    const long _pressTimeout;
    long _pressedTime;

    bool _pressed;
};

class AnalogButton : public AnalogSwitch{
public:
    AnalogButton(int pin, bool inverted = false, int pressTimeout = 180,int analogThreshold = 20);

    void update();
    bool pressed();

    void release();

private:

    bool _pressed;
    const long _pressTimeout;
    long _pressedTime;
};
