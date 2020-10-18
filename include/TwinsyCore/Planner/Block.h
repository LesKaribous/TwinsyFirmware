#pragma once

#include <string>

enum State{
    EMPTY,
    SCHEDULED,
    STARTED,
    BLOCKED,
    FAILED,
    FINISHED
};

typedef std::string BlockType;

class Block{
private:
    BlockType _type;
protected:
    State _state;

public:
    Block(BlockType bt) : _type(bt){};

    virtual bool exec() = 0;

    inline void setState(State state) { _state = state; }

    inline const State& getState()      const {return _state;}
    inline const BlockType& getType()   const {return _type;}
};
