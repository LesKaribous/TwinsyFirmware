#pragma once
#include "Core/Geometry.h"
#include "Core/Speed.h"

#include <list>
#include <FastCRC.h>

typedef unsigned char bit_t;

#define TWIN_ADRESS 0x3C

class RequestBase;

namespace Request{
    extern FastCRC8 CRC8;
    extern int badCRC_count;
    extern std::list<RequestBase> buffer;

    void init();
    void update();
    void eventloop();

    void badCRC();
}

enum class RequestType {
    INVALID     = B001,
    MOVE        = B010,
    PARAMETER   = B011,
    STATE       = B100
};

class RequestBase{
public :
    virtual void encode();
    virtual void decode();

    RequestBase(RequestType type, size_t size = 0, long timeout = 1000);
    RequestBase(size_t size, byte* packet);

    ~RequestBase();

    size_t size() const;
    byte* getContent() const;
    byte getByte(int i) const;
    byte crc() const;

private :
    byte* _content;
    byte _crc;
    byte _type;
    size_t _size;

    int _timeout;
};

class RequestMove : public RequestBase{
public :
    RequestMove(Origin origin, float x, float y, SpeedProfile sp = Speed::defaultProfile);

    virtual void encode();
    virtual void decode();
};

class RequestCalibration : public RequestBase{
public :
    RequestCalibration(int dist);

    virtual void encode();
    virtual void decode();
};

class RequestParameter : public RequestBase{
public :
    RequestParameter(char parameter, int value);

    virtual void encode();
    virtual void decode();
};

class RequestState : public RequestBase{
public :
    RequestState(char parameter, int value);

    virtual void encode();
    virtual void decode();
};