//
// Created by 陈磊 on 2020/8/8.
//

#ifndef LEETCODE_CPP_TIMER_H
#define LEETCODE_CPP_TIMER_H

#include "sys/timeb.h"

class timer {
public:
    timer();

    int cost();

private:
    timeb start{}, end{};
};


#endif //LEETCODE_CPP_TIMER_H
