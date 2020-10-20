#pragma once

class InputBase{
public:

    InputBase(int pin, bool pullup = false);
    void init();
    void update();

protected:
    int _pin;
    bool _pullup;
};

class AnalogInput : public InputBase{
public:
    AnalogInput(int pin, int threshold = 20);

    bool getDigitalState();//may be used as a digital input
    int getRawValue();  //Raw data from analogRead
    int getValue();     //Stable value

protected : 
    int _threshold;

};

class DigitalInput : public InputBase{
public :
    DigitalInput(int pin, bool inverted = false);

    bool getState();
    bool isInverted();
    
    void setInverted(bool state = true);

    bool changed();

protected:
    bool _inverted;
    bool _pState;
};

typedef DigitalInput Switch;