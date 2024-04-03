#include "Timer.h"

Timer::Timer() {
    reset();
}

void Timer::reset() {
    unsigned __int64 pf;
    QueryPerformanceFrequency((LARGE_INTEGER*)&pf);
    freq_ = 1.0 / static_cast<double>(pf);
    QueryPerformanceCounter((LARGE_INTEGER*)&baseTime_);
}

double Timer::seconds() {
    unsigned __int64 val;
    QueryPerformanceCounter((LARGE_INTEGER*)&val);
    return (val - baseTime_) * freq_;
}

double Timer::milliseconds() {
    return seconds() * 1000.0;
}
