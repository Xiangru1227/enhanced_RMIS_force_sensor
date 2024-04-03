#pragma once

#ifndef TIMER_H
#define TIMER_H

#include <Windows.h>

class Timer {
public:
    Timer();
    void reset();
    double seconds();
    double milliseconds();
private:
    double freq_;
    unsigned __int64 baseTime_;
};

#endif // TIMER_H
