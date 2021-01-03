/**
 * 14. Longest Common Prefix
 * Source: https://leetcode-cn.com/problems/longest-common-prefix/
 */

#ifndef LEETCODE_CPP_SOLUTION014_H
#define LEETCODE_CPP_SOLUTION014_H

#include <iostream>
#include <string>
#include <vector>

class solution014 {
public:
    std::string longestCommonPrefix1(std::vector<std::string> &strs) {
        if (strs.size() == 0) {
            return "";
        }

        std::string res = strs[0];
        for (size_t i = 1; i < strs.size() - 1; i++) {
            std::string current_common;
            for (size_t j = 0; j < strs[i].length() && j < strs[i+1].length() && strs[i][j] == strs[i+1][j]; j++) {
                current_common += strs[i][j];
            }
            if (res.length() > current_common.length()) {
                res = current_common;
            }
        }
        return res;
    }

    std::string longestCommonPrefix2(std::vector<std::string> &strs) {
        if (strs.size() == 0) {
            return "";
        }

        std::string current_common = strs[0];
        for (size_t i = 1; i < strs.size() - 1; i++) {
            int length = std::min(current_common.length(), strs[i].length());
            int j = 0;
            for (j = 0; j < length; j++) {
                if (current_common[j] != strs[i][j]) {
                    break;
                }
            }
            if (j < length) {
                current_common = current_common.substr(0, j);
            }
        }
        return current_common;
    }
};

static void test_solution014() {
    solution014 s;
    std::vector<std::string> strs = {"asbsc", "assjfshd", "asdasda"};
    std::cout << s.longestCommonPrefix2(strs) << std::endl;
}


#endif //LEETCODE_CPP_SOLUTION014_H
