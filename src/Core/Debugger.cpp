#include "Debugger.h"

#define C_DEBUG if(enabled)

using namespace Debugger;

bool Debugger::enabled = false;

void Debugger::init( int baudrate){
    Serial.begin(baudrate);
    Serial.println("Waiting for Serial...");
    waitForSerial();
}

bool Debugger::waitForSerial(int timeout){
    long time = millis();
    while (millis() - time < timeout){
        if(Serial){
            //Static mode
            Serial.println("Debug mode activated.");
            enabled = true;
            return true;
        }
    }
    //Cruise mode
    return false;
}

void Debugger::assert(String msg){
    C_DEBUG Serial.println(msg);
}

void Debugger::assert(String msg, String sender){
    C_DEBUG{
        Serial.print("[ ");
        Serial.print(sender);
        Serial.println(" ] : " + msg);
    }
}

void Debugger::assert(String msg, String file, String line){
    C_DEBUG{
        Serial.print("[LOG]: from ");
        Serial.print(file);
        Serial.print(" at line ");
        Serial.print(line);
        Serial.println(" : " + msg);
    }
}

void Debugger::logData(String name, float value){
    C_DEBUG {
        Serial.print(name + " : "); 
        Serial.println(value);
    }
}
