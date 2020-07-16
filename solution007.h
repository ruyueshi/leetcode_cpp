/*
 * Reverse Integer
 * Source: https://leetcode-cn.com/problems/reverse-integer/
 */

#ifndef SOLUTION007_H
#define SOLUTION007_H

#include <iostream>
#include <climits>

class solution007 {
public:
    int reverse(int x) {
        long int res = 0;
        while (x != 0) {
            res = res * 10 + x % 10;
            x = x / 10;
        }
        return res <= INT_MIN || res >= INT_MAX ? 0 : res;
    }
};

void test_solution007() {
    solution007 s;
    std::cout << s.reverse(1534236469) << std::endl;
    std::cout << s.reverse(-120) << std::endl;
    std::cout << INT_MAX << std::endl;
    std::cout << INT_MIN << std::endl;
}

#endif // SOLUTION007_H
