/**
 * 10. Regular Expression Matching
 * Source: https://leetcode-cn.com/problems/regular-expression-matching/
 */

#include <iostream>
#include <vector>

class Solution {
public:
    bool isMatch(std::string s, std::string p) {
        int m = s.length(), n = p.length();
        std::vector<std::vector<bool>> dp(m + 1, std::vector<bool>(n + 1));
        dp[0][0] = true;

        for (int i = 2; i <= n; i++) {
            if (p[i - 1] == '*') {
                dp[0][i] = dp[0][i - 2];
            }
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j - 1] == s[i - 1] || p[j - 1] == '.')
                    dp[i][j] = dp[i - 1][j - 1];
                else if (p[j - 1] == '*') {
                    if (p[j - 2] != s[i - 1] && p[j - 2] != '.')
                        dp[i][j] = dp[i][j - 2];
                    else
                        dp[i][j] = dp[i - 1][j] || dp[i][j - 1] || dp[i][j - 2];
                }
            }
        }
        return dp[m][n];
    }
};

int main() {
    Solution s;
    std::cout << s.isMatch("aa", "a*") << std::endl;
    return 0;
}
