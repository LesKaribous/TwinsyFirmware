#pragma once
#include "Core.h"

class MatchTimer{
public:
static void start();
static long time();
static long timeLeft();

private:
static IntervalTimer timer;

static const long MatchDuration = 100 * 1000 * 1000; //100 sec to micros
static const long MatchSafeStamp = 1000 * 1000;
static long startTime;
};

