#pragma once

#include <Arduino.h>

namespace Debugger{
    static bool enabled = false;
    inline void init( int baudrate = 115200 );

    void assert(String msg);
    void assert(String msg, String sender);
    void assert(String msg, String file, String line);

    template<typename T>
    void logData(String name, T value);
}

