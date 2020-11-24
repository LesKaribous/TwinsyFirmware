#include <Arduino.h>
#include "Debugger.h"
#include "Macro.h"

namespace Core{
    void init();
    void update();

    void stop();
    void emergencyStop();
}
