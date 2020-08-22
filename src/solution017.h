/**
 * 17. Letter Combinations of a Phone Number
 * Source: https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/
 */

#ifndef SOLUTION017_H
#define SOLUTION017_H

#include <iostream>
#include <vector>
#include <string>
#include <map>

class solution017
{
public:
    std::vector<std::string> letterCombinations(std::string digits) {
        if (digits.length() > 0) {
            backtrack("", digits);
        }
        return ans;
    }

    void backtrack(std::string current_combination, std::string residual_digits) {
        if (residual_digits.length() == 0) {
            this->ans.push_back(current_combination);
        } else {
            std::string alph = this->phone[residual_digits[0]];
            for (char &c : alph) {
                backtrack(current_combination + c, residual_digits.substr(1));
            }
        }
    }

private:
    std::map<char, std::string> phone = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
    std::vector<std::string> ans;
};

void test_solution017() {
    solution017 s;
    auto ans = s.letterCombinations("27");
    for (auto &res : ans) {
        std::cout << res << ",";
    }
    std::cout << std::endl;
}

#endif // SOLUTION017_H
