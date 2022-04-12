/**
 * 931. Minimum Falling Path Sum
 * Source: https://leetcode-cn.com/problems/minimum-falling-path-sum/
 */

#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
    int minFallingPathSum(std::vector<std::vector<int>> &matrix) {
        int n = matrix.size();
        int dp[n][n];  // dp[i][j]前i行，最小路径落到第i行第j列时的路径和
        for (int j = 0; j < n; j++)
            dp[0][j] = matrix[0][j];
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j == 0) {
                    dp[i][j] = std::min(dp[i - 1][j], dp[i - 1][j + 1]) + matrix[i][j];
                } else if (j == n - 1) {
                    dp[i][j] = std::min(dp[i - 1][j], dp[i - 1][j - 1]) + matrix[i][j];
                } else {
                    dp[i][j] = std::min({dp[i - 1][j - 1], dp[i - 1][j], dp[i - 1][j + 1]}) + matrix[i][j];
                }
            }
        }
        int res = INT_MAX;
        for (int j = 0; j < n; j++)
            res = std::min(res, dp[n - 1][j]);
        return res;
    }
};

int main() {
    Solution s;
    std::vector<std::vector<int>> matrix = {{2, 1, 3},
                                            {6, 5, 4},
                                            {7, 8, 9}};
    std::cout << s.minFallingPathSum(matrix) << std::endl;
    matrix = {{-19, 57},
              {-40, -5}};
    std::cout << s.minFallingPathSum(matrix) << std::endl;
    return 0;
}
