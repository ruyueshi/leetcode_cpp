/*
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
    std::string longestCommonPrefix(std::vector<std::string> &strs) {
        if (strs.size() == 0) {
            return "";
        } else if (strs.size() == 1) {
            return strs[0];
        }

        std::string res;

        for (int i = 0; i < strs.size() - 1; i++) {
            std::string current_common;
            for (int j = 0; j < strs[i].length() && j < strs[i+1].length() && strs[i][j] == strs[i+1][j]; j++) {
                current_common += strs[i][j];
            }
            if (i == 0 || (i > 0 && res.length() > current_common.length())) {
                res = current_common;
            }
        }
        return res;
    }
};

void test_solution014() {
    solution014 s;
    std::vector<std::string> strs = {"asbsc", "assjfshd", "asdasda"};
    std::cout << s.longestCommonPrefix(strs) << std::endl;
}


#endif //LEETCODE_CPP_SOLUTION014_H
