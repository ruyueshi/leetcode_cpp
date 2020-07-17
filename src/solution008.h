/*
 * String to Integer (atoi)
 * Source: https://leetcode-cn.com/problems/string-to-integer-atoi/
 */

#ifndef SOLUTION008_H
#define SOLUTION008_H

#include <iostream>
#include <string>
#include <climits>

class solution008 {
public:
    int myAtoi(std::string str) {
        long long res = 0;
        size_t i = 0;
        while (i < str.length() && str[i] == ' ') {
            i++;
        }
        if (i >= str.length() || !(str[i] == '+' || str[i] == '-' || (str[i] >= '0' && str[i] <= '9'))) {
            return 0;
        } else {
            bool is_negative = str[i] == '-' ? true : false;
            i = (str[i] == '+' || str[i] == '-') ? (i + 1) : i;
            size_t begin = i;
            while (i < str.length() && str[i] >= '0' && str[i] <= '9') {
                res = res * 10 + (str[i] - '0');
                if ((!is_negative && res > INT_MAX) || (is_negative && -res < INT_MIN)) {
                    return is_negative ? INT_MIN : INT_MAX;
                }
                i++;
            }
            return i == begin ? 0 : (is_negative ? -res : res);
        }
    }
};

void test_solution008() {
    solution008 s;
    std::cout << s.myAtoi(" -12314er") << std::endl;
    std::string str;
    while (std::cin >> str) {
        std::cout << s.myAtoi(str) << std::endl;
    }
}

#endif // SOLUTION008_H
