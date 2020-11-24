#include "Core.h"
#include "Request.h"

//Request global definition
FastCRC8 Request::CRC8;

using namespace Request;

void Request::badCRC(){
    badCRC_count++;
}

/**
 * @brief Base abstract construtor
 */

RequestBase::RequestBase(RequestType type, size_t size, long timeout){
    _size = size + 1;
    _content = new byte[_size];
    _type = byte(type);

    _timeout = timeout;
}

RequestBase::RequestBase(size_t size, byte* packet){
    const size_t content_size = size - 1;
    byte content[content_size];

    for (size_t i = 0; i < content_size; i++)
        content[i] = packet[i];

    
}

RequestBase::~RequestBase(){
    delete[] _content;
}

void RequestBase::encode(){
    _content[0] = _type;
    _crc = Request::CRC8.smbus(this->_content, this->_size);
}

void RequestBase::decode(){
    _type = _content[0];
}

size_t RequestBase::size() const{
    return _size;
}

byte* RequestBase::getContent() const{
    return _content;
}

byte RequestBase::getByte(int i) const{
    if(i < _size)
        return _content[i];
    else return 0;
}

byte RequestBase::crc() const{
    return _crc;
}