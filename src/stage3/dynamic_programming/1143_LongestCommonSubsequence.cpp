/**
 * 1143. Longest Common Subsequence
 * Source: https://leetcode-cn.com/problems/longest-common-subsequence/
 */

#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    int longestCommonSubsequence(std::string text1, std::string text2) {
        int m = text1.length(), n = text2.length();
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m][n];
    }
};

int main() {
    Solution s;
    std::cout << s.longestCommonSubsequence("abcde", "ace") << std::endl;
    std::cout << s.longestCommonSubsequence("abc", "abc") << std::endl;
    std::cout << s.longestCommonSubsequence("abc", "def") << std::endl;
    return 0;
}
