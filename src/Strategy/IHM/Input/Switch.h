#pragma once
#include "InputBase.h"

typedef DigitalInput Switch;

class AnalogSwitch : public InputBase{
public:
    AnalogSwitch(int pin, bool inverted = false);

    bool getRawState();
    bool getState();

    bool isInverted();

protected:
    bool _inverted;

};
