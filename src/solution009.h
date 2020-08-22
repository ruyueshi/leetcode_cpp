/**
 * Palindrome Number
 * Source: https://leetcode-cn.com/problems/palindrome-number/
 */

#ifndef SOLUTION009_H
#define SOLUTION009_H

#include <iostream>
#include <string>
#include <algorithm>

class solution009 {
public:
    bool isPalindrome1(int x) {
        if (x < 0) {
            return false;
        }

        std::string num = std::to_string(x);
        int l = num.length();
        for (int i = 0; i <= l/2; i++) {
            if (num[i] != num[l-1-i]) {
                return false;
            }
        }
        return true;
    }

    // cost more time than the first method
    bool isPalindrome2(int x) {
        std::string num = std::to_string(x);
        std::string temp = num;
        std::reverse(temp.begin(), temp.end());
        return num == temp;
    }
};

void test_solution009() {
    solution009 s;
    std::cout << s.isPalindrome2(9) << std::endl;
    std::cout << s.isPalindrome2(101) << std::endl;
    std::cout << s.isPalindrome2(100) << std::endl;
    std::cout << s.isPalindrome2(100001) << std::endl;
}

#endif // SOLUTION009_H
