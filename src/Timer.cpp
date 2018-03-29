//
// Created by pasta on 19/02/18.
//

#include <iostream>
#include "Timer.h"

Timer::Timer() {
    mLastTimeSample = tClock::now();
}

float Timer::calcDeltaTimeInMs() {
    tTimePoint now = tClock::now();

    // STL is ugly
    long delta = std::chrono::duration_cast<std::chrono::milliseconds>(now - mLastTimeSample).count();
    // Reset the timer with the new time
    mLastTimeSample = now;

    return delta;
}

void Timer::reset() {
    mLastTimeSample = tClock::now();
}
