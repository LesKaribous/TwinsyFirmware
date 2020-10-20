#pragma once
#include "InputBase.h"

class Button : public DigitalInput{
public :

    Button(int pin, long pressTimeout = 180, bool inverted = false);

    void update();
    bool pressed();

    void release();
    
private:
    const long _pressTimeout;
    long _pressedTime;

    bool _pressed;
};

class AnalogButton : public AnalogInput{

    AnalogButton(int pin, long pressThreshold = 180,int analogThreshol = 20, bool inverted = false);

    void update();
    bool pressed();

    void release();

private:
    const long _pressTimeout;
    long _pressedTime;
    bool _inverted;

    bool _pressed;

};
