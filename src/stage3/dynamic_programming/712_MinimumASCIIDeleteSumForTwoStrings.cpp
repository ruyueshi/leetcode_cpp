/**
 * 712. Minimum ASCII Delete Sum for Two Strings
 * Source: https://leetcode-cn.com/problems/minimum-ascii-delete-sum-for-two-strings/
 */

#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    int minimumDeleteSum(std::string s1, std::string s2) {
        int m = s1.length(), n = s2.length();
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1));
        for (int i = 1; i <= m; i++)
            dp[i][0] = dp[i - 1][0] + s1[i - 1];
        for (int j = 1; j <= n; j++)
            dp[0][j] = dp[0][j - 1] + s2[j - 1];
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = std::min(dp[i - 1][j] + s1[i - 1], dp[i][j - 1] + s2[j - 1]);
                }
            }
        }
        return dp[m][n];
    }
};

int main() {
    Solution s;
    std::cout << s.minimumDeleteSum("sea", "eat") << std::endl;
    std::cout << s.minimumDeleteSum("delete", "leet") << std::endl;
    // for (int i = 0; i < 26; i++) {
    //     char ch = 'a' + i;
    //     std::cout << ch << ": " << int(ch) << std::endl;
    // }
    return 0;
}
