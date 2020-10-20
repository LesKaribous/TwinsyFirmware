#pragma once

#include "Input/InputBase.h"
#include "Input/Button.h"

namespace Inputs{
    void init();
    void update();
    void eventloop();

    extern  Button checkListButton;
    extern Switch strategySwitch;
    extern Switch teamSwitch;
    extern Switch avoidanceSwitch;
}