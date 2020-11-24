#include "Core/MatchTimer.h"
#include "Core.h"

long MatchTimer::startTime;
IntervalTimer MatchTimer::timer;

void MatchTimer::start()
{
    startTime = millis();
    //timer.begin(Core::endMatch, MatchDuration - MatchSafeStamp); 
}
long MatchTimer::time()
{
    return millis() - startTime;
}

long MatchTimer::timeLeft()
{
    return (MatchDuration / 1000) - (millis() - startTime);
}