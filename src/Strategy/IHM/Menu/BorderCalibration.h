#ifndef BORDERCALIBRATION_H
#define BORDERCALIBRATION_H

class BorderCalibration
{
    static enum State {
        WAITING,
        WORKING,
        DONE
    } state;

    static bool needDraw;
    static long completeTime;
    static const char *toMessage(State s);

public:
    static void init();
    static void update();
    static void draw();

    static bool isComplete();
    static void done();
};

#endif