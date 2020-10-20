#pragma once

class InputBase{
public:

    InputBase(int pin, bool pullup = false);
    virtual void init();
    virtual void update();

protected:
    int _pin;
    bool _pullup;
};

class AnalogInput : public InputBase{
public:
    AnalogInput(int pin, int threshold = 20);

    virtual void update();

    bool getDigitalState(); //may be used as a digital input
    int getRawValue();      //Raw data from analogRead
    int getValue();         //Stable value

    bool changed();

protected : 
    int _threshold;
    int _pValue;
    int _value;
};

class DigitalInput : public InputBase{
public :
    DigitalInput(int pin, bool inverted = false);

    virtual void update();

    bool getState();
    bool changed();
    bool isInverted();
    void setInverted(bool state = true);

protected:
    bool _inverted;
    bool _pState;
    bool _state;
};