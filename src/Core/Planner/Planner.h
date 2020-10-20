#pragma once

#include <vector>
#include "Planner/Block.h"

class Planner{
    static std::vector<Block*> program;
    static int currentBlock;
    static bool running;
public:

    static void init();
    static void appendBlock(Block* block);
    static void removeBlock(int id);

    static void execAll();
    static void exec();

    static void start();
    static void stop();

    static void flush();

    static bool isRunning();
};


