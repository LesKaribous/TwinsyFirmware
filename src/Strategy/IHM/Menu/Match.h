#ifndef MENU_MATCH_H
#define MENU_MATCH_H

class Match
{
    static long goStart;
    static bool needDraw;

public:
    static void init();
    static void update();
    static void draw();
};

#endif