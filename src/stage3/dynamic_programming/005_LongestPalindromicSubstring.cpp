/**
 * 516. Longest Palindromic Subsequence
 * Source: https://leetcode-cn.com/problems/longest-palindromic-subsequence/
 */

#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        int n = s.length();
        std::vector<std::vector<bool>> dp(n, std::vector<bool>(n));  // dp[i][j]用来判断s[i...j]是否是回文子串
        int max_len = 1, max_start = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j]) {
                    if (j - 1 > i + 1) {
                        dp[i][j] = dp[i + 1][j - 1];
                    } else {
                        dp[i][j] = true;  // "aa", "aba"
                    }
                    if (dp[i][j]) {
                        if (j - i + 1 > max_len) {
                            max_len = j - i + 1;
                            max_start = i;
                        }
                    }
                }
            }
        }

        return s.substr(max_start, max_len);
    }
};

int main() {
    Solution s;
    std::cout << s.longestPalindrome("a") << std::endl;
    std::cout << s.longestPalindrome("babad") << std::endl;
    return 0;
}
