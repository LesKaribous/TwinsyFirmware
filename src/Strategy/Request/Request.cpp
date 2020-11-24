#include "Core.h"
#ifdef STRATEGY
#include "Request.h"

#include <Wire.h>

namespace Request{
    void sendRequest(RequestBase* rq);
}

void Request::init(){
	Wire.begin(TWIN_ADRESS);
}

void Request::update(){

}

void Request::eventloop(){

}

void Request::sendRequest(RequestBase* rq){
    rq->encode();

    // Envoi des données
    Wire.beginTransmission(TWIN_ADRESS);
    for(int i=0; i < rq->size(); i++) 
        Wire.write(rq->getByte(i));
    
    Wire.write(rq->crc());
    Wire.endTransmission();
    delay(100);
}



#endif