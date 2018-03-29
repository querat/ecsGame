//
// Created by pasta on 19/02/18.
//

#ifndef ALLEGRO_TIMER_H
#define ALLEGRO_TIMER_H

#include <chrono>

// auto currentTime = std::chrono::steady_clock::now();
// auto elapsed = previousTime - currentTime;
//
// ... do stuff with elapsed time...
// float elapsed_f = elapsed.count();
//
// previousTime = currentTime;

class Timer {

    using tClock        = std::chrono::high_resolution_clock;
    using tMilliseconds = std::chrono::milliseconds;
    using tTimePoint    = std::chrono::time_point<tClock>;

private:

    tTimePoint mLastTimeSample;

public:
    Timer();
    ~Timer() = default;
    float calcDeltaTimeInMs();
    void reset();
};


#endif //ALLEGRO_TIMER_H
