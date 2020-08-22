/**
 * Regular Expression Matching
 * Source: https://leetcode-cn.com/problems/regular-expression-matching/
 * Dynamic programming
 */

#ifndef SOLUTION010_H
#define SOLUTION010_H

#include <iostream>
#include <vector>

class solution010 {
public:
    bool isMatch(std::string s, std::string p) {
        f = new int *[s.length() + 1];
        for (size_t i = 0; i <= s.length(); i++) {
            f[i] = new int[p.length() + 1];
            for (size_t j = 0; j <= p.length(); j++) {
                f[i][j] = 0;
            }
        }

        int res = match(0, 0, s, p);

        for (size_t i = 0; i <= s.length(); i++) {
            delete [] f[i];
        }
        delete [] f;
        return res;
    }

    bool match(size_t i, size_t j, std::string s, std::string p) {
        if (f[i][j] != 0) {
            return f[i][j] == 1;
        }
        bool res;
        if (j == p.length()) {
            res = i == s.length();
        } else {
            bool current_match = i < s.length() && (s[i] == p[j] || p[j] == '.');
            if (j + 1 < p.length() && p[j+1] == '*') {
                res = match(i, j+2, s, p) || (current_match && match(i+1, j, s, p));
            } else {
                res = current_match && match(i+1, j+1, s, p);
            }
        }
        f[i][j] = res ? 1 : 2;
        return res;
    }
private:
    int **f;
};

void test_solution010() {
    solution010 s;
    std::cout << s.isMatch("aa", "a") << std::endl;
    std::cout << s.isMatch("aa", "a*") << std::endl;
    std::cout << s.isMatch("ab", ".*") << std::endl;
    std::cout << s.isMatch("aab", "c*a*b") << std::endl;
    std::cout << s.isMatch("mississippi", "mis*is*p*.") << std::endl;
    std::cout << s.isMatch("aaaaaaaaaaaaab", "a*a*a*a*a*a*a*a*a*a*c") << std::endl;
}

#endif // SOLUTION010_H
