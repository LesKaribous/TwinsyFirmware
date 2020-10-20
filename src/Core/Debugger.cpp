#include "Debugger.h"

#define DEBUG if(enable)

using namespace Debugger;

bool Debugger::enable = false;

void Debugger::init( int baudrate){
    Serial.begin(baudrate);
    while (!Serial);
    
    Serial.println("Debugger activated");
    enable = true;
}

void Debugger::assert(String msg){
    DEBUG Serial.println(msg);
}

void Debugger::assert(String msg, String sender){
    DEBUG{
        Serial.print("[ ");
        Serial.print(sender);
        Serial.println(" ] : " + msg);
    }
}

void Debugger::assert(String msg, String file, String line){
    DEBUG{
        Serial.print("[LOG]: from ");
        Serial.print(file);
        Serial.print(" at line ");
        Serial.print(line);
        Serial.println(" : " + msg);
    }
}

template<typename T>
void Debugger::logData(String name, T value){
    DEBUG {
        Serial.print(name + " : "); 
        Serial.println(value);
    }
}
