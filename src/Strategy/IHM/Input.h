#pragma once

#include "Input/InputBase.h"
#include "Input/Button.h"
#include "Input/Switch.h"

namespace Inputs{
    void init();
    void update();
    void eventloop();

    extern AnalogButton checkListButton;
    extern Switch strategySwitch;
    extern Switch avoidanceSwitch;
    extern AnalogSwitch teamSwitch;
}