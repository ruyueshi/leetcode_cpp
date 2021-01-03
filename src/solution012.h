/**
 * 12. Integer to Roman
 * Source: https://leetcode-cn.com/problems/integer-to-roman/
 */

#ifndef LEETCODE_CPP_SOLUTION012_H
#define LEETCODE_CPP_SOLUTION012_H

#include <iostream>
#include <string>

class solution012 {
public:
    std::string intToRoman(int num) {
        int key[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        std::string value[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        std::string ans = "";
        int index = 0;
        while (index < 13) {
            if (num >= key[index]) {
                ans += value[index];
                num -= key[index];
            } else {
                index++;
            }
        }
        return ans;
    }
};

static void test_solution012() {
    solution012 s;
    std::cout << s.intToRoman(3) << std::endl;
    std::cout << s.intToRoman(4) << std::endl;
    std::cout << s.intToRoman(9) << std::endl;
    std::cout << s.intToRoman(58) << std::endl;
    std::cout << s.intToRoman(1994) << std::endl;
}

#endif //LEETCODE_CPP_SOLUTION012_H
