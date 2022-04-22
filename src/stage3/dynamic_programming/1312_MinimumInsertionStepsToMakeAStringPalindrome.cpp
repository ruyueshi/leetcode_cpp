/**
 * 1312. Minimum Insertion Steps to Make a String Palindrome
 * Source: https://leetcode-cn.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/
 */

#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    int minInsertions(std::string s) {
        int n = s.length();
        std::vector<std::vector<int>> dp(n, std::vector<int>(n));

        for (int i = n - 1; i >= 0; i--) {
            dp[i][i] = 0;
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1];  // 注意，此处i+1可能会大于j-1，说明i==j-1，则有dp[i][j] = 0
                } else {
                    dp[i][j] = std::min(dp[i + 1][j], dp[i][j - 1]) + 1;
                }
            }
        }

        return dp[0][n - 1];
    }
};

int main() {
    Solution s;
    std::cout << s.minInsertions("zzazz") << std::endl;
    std::cout << s.minInsertions("mbadm") << std::endl;
    std::cout << s.minInsertions("leetcode") << std::endl;
    return 0;
}
