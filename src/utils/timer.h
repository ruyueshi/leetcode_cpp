//
// Created by 陈磊 on 2020/8/8.
//

#ifndef LEETCODE_CPP_TIMER_H
#define LEETCODE_CPP_TIMER_H

#include <iostream>
#include "sys/time.h"

class timer {
public:
    timer() {
        gettimeofday(&this->start, nullptr);
    }

    void reset() {
        gettimeofday(&this->start, nullptr);
    }

    double cost() {
        gettimeofday(&this->end, nullptr);
        double diff = (end.tv_sec * 1000.0 + end.tv_usec / 1000.0) - (start.tv_sec * 1000.0 + start.tv_usec / 1000.0);
        return diff;
    }

private:
    struct timeval start{}, end{};
};


#endif //LEETCODE_CPP_TIMER_H
