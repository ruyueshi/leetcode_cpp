/**
 * 22. Generate Parentheses
 * Source: https://leetcode-cn.com/problems/generate-parentheses/
 */

#ifndef SOLUTION022_H
#define SOLUTION022_H

#include <iostream>
#include <vector>

class solution022 {
public:
    std::vector<std::string> generateParenthesis(int n) {
        this->str_length = n * 2;
        this->backtrack("(", 1);
        return ans;
    }
private:
    std::vector<std::string> ans;
    std::string single_parenthesis = "()";
    size_t str_length;

    void backtrack(std::string sub_parenthesis, int left_num) {
        if (left_num < sub_parenthesis.length()/2.0 || left_num > this->str_length/2.0) {
            return;
        }
        if (sub_parenthesis.length() == this->str_length) {
            if (left_num == this->str_length/2) {
                ans.push_back(sub_parenthesis);
            }
            return;
        }
        for (int i = 0; i < 2; i++) {
            this->backtrack(sub_parenthesis + single_parenthesis[i], left_num + (1-i));
        }
    }
};

static void test_solution022() {
    solution022 s;
    std::vector<std::string> ans = s.generateParenthesis(3);
    for (const auto & str : ans) {
        std::cout << str << std::endl;
    }
}

#endif // SOLUTION022_H
