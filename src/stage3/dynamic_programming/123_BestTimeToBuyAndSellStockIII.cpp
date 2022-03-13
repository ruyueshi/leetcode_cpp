/**
 * 123. Best Time to Buy and Sell Stock III
 * Source: https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/
 */

#include <iostream>
#include <vector>

// 动态规划
class SolutionV1 {
public:
    int maxProfit(std::vector<int> &&prices) {
        int n = prices.size(), max_k = 2;
        int dp[n][max_k + 1][2];
        for (int k = 0; k <= max_k; k++) {
            dp[0][k][0] = 0;
            dp[0][k][1] = -prices[0];
        }
        for (int i = 1; i < n; i++) {
            dp[i][0][0] = 0;
            dp[i][0][1] = -prices[0];
        }
        for (int i = 1; i < n; i++) {
            for (int k = 1; k <= max_k; k++) {
                // 第i天不持有股票，且最大交易次数为k
                dp[i][k][0] = std::max(dp[i - 1][k][0], dp[i - 1][k][1] + prices[i]);  // std::max(现在不持有股票并且前一天也不持有股票, 前一天持有股票且今天把股票卖了)
                // 第i天持有股票，且最大交易次数为k
                dp[i][k][1] = std::max(dp[i - 1][k][1], dp[i - 1][k - 1][0] - prices[i]);  // std::max(现在持有股票并且前一天也持有股票, 前一天不持有股票（前一天的最大交易次数为k-1）且今天买入股票)
            }
        }
        return dp[n - 1][max_k][0];
    }
};

// 优化V1
// 压缩空间
class SolutionV2 {
public:
    int maxProfit(std::vector<int> &&prices) {
        int n = prices.size();
        int dp_i10 = 0, dp_i11 = -prices[0], dp_i00 = 0, dp_i21 = -prices[0], dp_i20 = 0;
        for (int i = 1; i < n; i++) {
            // dp[i][2][0] = std::max(dp[i - 1][2][0], dp[i - 1][2][1] + prices[i]);
            // dp[i][2][1] = std::max(dp[i - 1][2][1], dp[i - 1][1][0] - prices[i]);
            // dp[i][1][0] = std::max(dp[i - 1][1][0], dp[i - 1][1][1] + prices[i]);
            // dp[i][1][1] = std::max(dp[i - 1][1][1], dp[i - 1][0][0] - prices[i]);
            dp_i20 = std::max(dp_i20, dp_i21 + prices[i]);
            dp_i21 = std::max(dp_i21, dp_i10 - prices[i]);
            dp_i10 = std::max(dp_i10, dp_i11 + prices[i]);
            dp_i11 = std::max(dp_i11, dp_i00 - prices[i]);
        }
        return dp_i20;
    }
};

int main() {
    SolutionV2 s;
    std::cout << s.maxProfit({3, 3, 5, 0, 0, 3, 1, 4}) << std::endl;
    std::cout << s.maxProfit({1, 2, 3, 4, 5}) << std::endl;
    std::cout << s.maxProfit({1}) << std::endl;
    std::cout << s.maxProfit({1, 2, 4, 2, 5, 7, 2, 4, 9, 0}) << std::endl;
    return 0;
}
