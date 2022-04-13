/**
 * 72. Edit Distance
 * Source: https://leetcode-cn.com/problems/edit-distance/
 */

#include <algorithm>
#include <iostream>
#include <string>

class Solution {
public:
    int minDistance(std::string word1, std::string word2) {
        int m = word1.size(), n = word2.size();
        int dp[m + 1][n + 1];
        dp[0][0] = 0;
        for (int i = 1; i <= m; i++)
            dp[i][0] = i;
        for (int j = 1; j <= n; j++)
            dp[0][j] = j;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = std::min({dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + 1});  // 删除、增加、替换
            }
        }
        return dp[m][n];
    }
};

int main() {
    Solution s;
    std::cout << s.minDistance("horse", "ros") << std::endl;
    std::cout << s.minDistance("intention", "execution") << std::endl;
    return 0;
}
