/**
 * 174. Dungeon Game
 * Source: https://leetcode-cn.com/problems/dungeon-game/
 */

#include <iostream>
#include <vector>

class Solution {
public:
    // 有问题
    int calculateMinimumHP_v1(std::vector<std::vector<int>> &dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        std::vector<std::vector<int>> dp(m, std::vector<int>(n));  // dp[i][j]表示从(0,0)能够安全到(i,j)所需的初始健康点数
        std::vector<std::vector<int>> sum(m, std::vector<int>(n));  // sum[i][j]表示从(0,0)到达(i,j)时剩余的健康点数
        dp[0][0] = std::max(1, 1 - dungeon[0][0]);
        sum[0][0] = dp[0][0] + dungeon[0][0];
        for (int i = 1; i < m; i++) {
            int remain = sum[i - 1][0] + dungeon[i][0];
            dp[i][0] = dp[i - 1][0] + std::max(0, 1 - remain);
            sum[i][0] = (dp[i][0] - dp[i - 1][0]) + sum[i - 1][0] + dungeon[i][0];
        }
        for (int j = 1; j < n; j++) {
            int remain = dp[0][j - 1] + sum[0][j - 1] + dungeon[0][j];
            dp[0][j] = dp[0][j - 1] + std::max(0, 1 - remain);
            sum[0][j] = (dp[0][j] - dp[0][j - 1]) + sum[0][j - 1] + dungeon[0][j];
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                int remain_up = sum[i - 1][j] + dungeon[i][j];
                int remain_left = sum[i][j - 1] + dungeon[i][j];
                int dp_pre_up = dp[i - 1][j] + std::max(0, 1 - remain_up);
                int dp_pre_left = dp[i][j - 1] + std::max(0, 1 - remain_left);
                if (dp_pre_up < dp_pre_left) {
                    dp[i][j] = dp_pre_up;
                    sum[i][j] = (dp[i][j] - dp[i - 1][j]) + sum[i - 1][j] + dungeon[i][j];
                } else if (dp_pre_up) {
                    dp[i][j] = dp_pre_left;
                    sum[i][j] = (dp[i][j] - dp[i][j - 1]) + sum[i][j - 1] + dungeon[i][j];
                }
            }
        }
        return dp[m - 1][n - 1];
    }

    int calculateMinimumHP(std::vector<std::vector<int>> &dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        // std::vector<std::vector<int>> dp(m, std::vector<int>(n));  // dp[i][j]表示从(i,j)能够安全到(m-1,n-1)所需的初始健康点数
        int dp[m][n];
        dp[m - 1][n - 1] = std::max(1, 1 - dungeon[m - 1][n - 1]);
        for (int i = m - 2; i >= 0; i--) {
            dp[i][n - 1] = std::max(1, dp[i + 1][n - 1] - dungeon[i][n - 1]);
        }
        for (int j = n - 2; j >= 0; j--) {
            dp[m - 1][j] = std::max(1, dp[m - 1][j + 1] - dungeon[m - 1][j]);
        }
        for (int i = m - 2; i >= 0; i--) {
            for (int j = n - 2; j >= 0; j--) {
                int res = std::min(dp[i][j + 1], dp[i + 1][j]) - dungeon[i][j];
                dp[i][j] = std::max(1, res);
            }
        }
        return dp[0][0];
    }
};

int main() {
    Solution s;
    std::vector<std::vector<int>> d = {{-2, -3,  3},
                                       {-5, -10, 1},
                                       {10, 30,  -5}};
    std::cout << s.calculateMinimumHP(d) << std::endl;
    d = {{1,  -3, 3},
         {0,  -2, 0},
         {-3, -3, -3}};
    std::cout << s.calculateMinimumHP(d) << std::endl;
    return 0;
}
