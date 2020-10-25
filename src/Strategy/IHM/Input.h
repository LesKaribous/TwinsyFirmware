#pragma once

#include "Input/InputBase.h"
#include "Input/Button.h"
#include "Input/Switch.h"

namespace Inputs{
    void init();
    void update();
    void eventloop();

    extern Switch starter;
    extern Switch jumperRobotType;
    extern AnalogButton buttonChecklist;
    extern Switch switchStrategy;
    extern Switch switchAvoidance;
    extern AnalogSwitch switchTeam;
}