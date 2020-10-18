#include "Debugger.h"
    
namespace Debugger{

    inline void init( int baudrate){ 
        Serial.begin(baudrate);
        enabled = true;
    }

    void assert(String msg){
        Serial.println(msg);
    }

    void assert(String msg, String sender){
        Serial.print("[ ");
        Serial.print(sender);
        Serial.println(" ] : " + msg);
    }

    void assert(String msg, String file, String line){
        Serial.print("[LOG]: from ");
        Serial.print(file);
        Serial.print(" at line ");
        Serial.print(line);
        Serial.println(" : " + msg);
    }

    template<typename T>
    void logData(String name, T value){
        Serial.print(name + " : "); Serial.println(value);
    }
}
