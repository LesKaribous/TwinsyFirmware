#pragma once

#include <Arduino.h>

namespace Debugger{
    extern bool enabled;
    void init( int baudrate = 9600 );

    bool waitForSerial(int timeout = 4000);

    void assert(String msg);
    void assert(String msg, String sender);
    void assert(String msg, String file, String line);


    void logData(String name, float value);
}

