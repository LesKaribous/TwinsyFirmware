#pragma once

class MenuBase{
public:
    virtual void init() = 0;
    virtual void draw() = 0;

    virtual void processEvent() = 0;

protected :
    MenuBase();
    static int lastID;

    bool needDraw;

private :
    bool id;

};
