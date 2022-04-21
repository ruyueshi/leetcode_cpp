/**
 * 516. Longest Palindromic Subsequence
 * Source: https://leetcode-cn.com/problems/longest-palindromic-subsequence/
 */

#include <cstring>
#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    int longestPalindromeSubseq(std::string s) {
        int n = s.length();
        std::vector<std::vector<int>> dp(n, std::vector<int>(n));
        for (int i = n - 1; i >= 0; i--) {
            dp[i][i] = 1;
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j])
                    dp[i][j] = dp[i + 1][j - 1] + 2;  // 注意，此处i+1可能会大于j-1，说明i==j-1，则dp[i][j] = 2，而此时dp[i+1][j-1]为0，因此可以不用拿出来考虑
                else
                    dp[i][j] = std::max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
        return dp[0][n - 1];
    }
};

int main() {
    Solution s;
    std::cout << s.longestPalindromeSubseq("bbbab") << std::endl;
    std::cout << s.longestPalindromeSubseq("cbbd") << std::endl;
    return 0;
}
