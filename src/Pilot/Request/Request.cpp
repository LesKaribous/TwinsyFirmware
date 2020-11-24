#include "Core.h"
#ifdef STRATEGY

#include "Request.h"
#include "Wire.h"

namespace Request{
    void receiveEvent(int bytesCount);
    void requestEvent();
}

void Request::receiveEvent(int bytesCount){
    if(bytesCount > 0){
        byte byteBuffer[bytesCount];
        Wire.readBytes(byteBuffer, bytesCount); //Read all bytes
        byte crc = byteBuffer[bytesCount - 1]; //Last byte is CRC

        const size_t content_size = bytesCount - 1;
        byte content[content_size];

        byte crcNav = CRC8.smbus(content, content_size); //Generate CRC
        if (crcNav == crc){
            buffer.push_back(RequestBase(bytesCount, byteBuffer));
        }
    }
}

void Request::requestEvent(){

}


#endif