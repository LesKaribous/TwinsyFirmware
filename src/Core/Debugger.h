#pragma once

#include <Arduino.h>

namespace Debugger{
    extern bool enable;
    void init( int baudrate = 9600 );

    void assert(String msg);
    void assert(String msg, String sender);
    void assert(String msg, String file, String line);


    void logData(String name, float value);
}

