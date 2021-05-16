//
// Created by 陈磊 on 2020/8/8.
//

#include <iostream>
#include "include/timer.h"

timer::timer() {
    ftime(&this->start);
}

int timer::cost() {
    ftime(&this->end);
    long time = (end.time * 1000 + end.millitm) - (start.time * 1000 + start.millitm);
    std::cout << "cost time " << time << " ms\n";
    return (int)time;
}
