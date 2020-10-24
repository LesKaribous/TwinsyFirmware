#pragma once

#define SAMPLING_COUNT 5

class InputBase{
public:

    InputBase(int pin, bool pullup = false);
    virtual void init();

protected:
    int _pin;

private:
    bool _pullup;
};

class AnalogInput : public InputBase{
public:
    AnalogInput(int pin);

    int getRawValue();      //Raw data from analogRead
    int getValue();         //Stable value
};

class DigitalInput : public InputBase{
public :
    DigitalInput(int pin, bool inverted = false);

    bool getState();
    bool getRawState();
    bool isInverted();

protected:
    bool _inverted;
};
