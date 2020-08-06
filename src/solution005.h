/*
 * Longest Palindromic Substring
 * Source: https://leetcode-cn.com/problems/longest-palindromic-substring/
 * Dynamic programming
 */

#ifndef SOLUTION005_H
#define SOLUTION005_H

#include <iostream>
#include <string>
#include <vector>
#include "stdio.h"

class solution005 {
public:
    // time complexity: O(n*n)
    // space complexity: O(n*n)
    std::string longestPalindrome1(std::string s) {
        std::string longest_substring = "";
        int length = s.length();
        std::vector<std::vector<bool>> F(length, std::vector<bool>(length, false)); // F[i][j] indicates whether the substring s[i:j] is a palindrome

        for (int j = 0; j < length; j++) {
            for (int i = 0; i < j + 1; i++) {
                if (j - i <= 1) {
                    if (s[i] == s[j]) {
                        F[i][j] = true;
                        if (j - i + 1 > int(longest_substring.length())) {
                            longest_substring.assign(s, i, j - i + 1);
                        }
                    }
                } else {
                    if (s[i] == s[j] && F[i + 1][j - 1]) {
                        F[i][j] = true;
                        if (j - i + 1 > int(longest_substring.length())) {
                            longest_substring.assign(s, i, j - i + 1);
                        }
                    }
                }
            }
        }

        return longest_substring;
    }

    // time complexity: O(n*n)
    // space complexity: O(n)
    std::string longestPalindrome2(std::string s) {
        std::string longest_substring = "";
        int length = s.length();
        std::vector<bool> previous_state(length, false);
        std::vector<bool> current_state(length, false);

        for (int j = 0; j < length; j++) {
            for (int i = 0; i < j + 1; i++) {
                if (j - i <= 1) {
                    if (s[i] == s[j]) {
                        current_state[i] = true;
                        if (j - i + 1 > int(longest_substring.length())) {
                            longest_substring.assign(s, i, j - i + 1);
                        }
                    }
                } else {
                    if (s[i] == s[j] && previous_state[i + 1]) {
                        current_state[i] = true;
                        if (j - i + 1 > int(longest_substring.length())) {
                            longest_substring.assign(s, i, j - i + 1);
                        }
                    }
                }
            }
            previous_state = current_state;
            current_state.clear();
            current_state.resize(length, false);
        }

        return longest_substring;
    }
};

void test_solution005() {
    solution005 s;
    std::cout << s.longestPalindrome2("babad") << std::endl;
    std::string str;
    while (std::cin >> str) {
        std::cout << s.longestPalindrome2(str) << std::endl;
    }
}

#endif // SOLUTION005_H
