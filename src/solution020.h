/*
 * 20. Valid Parentheses
 * Source: https://leetcode-cn.com/problems/valid-parentheses/
 */

#ifndef LEETCODE_CPP_SOLUTION020_H
#define LEETCODE_CPP_SOLUTION020_H

#include <iostream>
#include <string>
#include <stack>

class solution020 {
public:
    bool isValid(std::string s) {
        std::stack<char> stk;
        for (size_t i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                stk.push(s[i]);
            } else {
                if (!stk.empty() && match(stk.top(), s[i])) {
                    stk.pop();
                } else {
                    stk.push(s[i]);
                }
            }
        }
        return stk.empty();
    }

    bool match(char l, char r) {
        switch (l) {
            case '(': return r == ')';
            case '[': return r == ']';
            case '{': return r == '}';
            default: return false;
        }
    }
};

void test_solution020() {
    solution020 s;
    std::string str[5] = {"()", "(){}[]", "(]", "([)]", "{[]}"};
    for (auto &i : str) {
        std::cout << s.isValid(i) << std::endl;
    }
}

#endif //LEETCODE_CPP_SOLUTION020_H
