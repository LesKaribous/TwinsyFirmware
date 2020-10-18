#ifndef CHECKLIST_H
#define CHECKLIST_H

#include <string>

class Checklist{
    static enum Type{
        SECONDARY_ROBOT,
        EXPERIMENT,
        CHECK_ELEMENT,
        CLEAN_TABLE,
        PLACE_BEACON,
        CHECKED,
        SIZE //Use for array readding only
    }current;

static bool needDraw;
static long completeTime;

static const char* toTitle(Type t);
static const char* toText(Type t);

public:
    static void init();
    static void update();
    static void draw();
    static bool isComplete();
};

#endif