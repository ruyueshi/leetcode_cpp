/**
 * 309. Best Time to Buy and Sell Stock with Cooldown
 * Source: https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
 */

#include <iostream>
#include <vector>

// 动态规划
class SolutionV1 {
public:
    int maxProfit(std::vector<int> &&prices) {
        int n = prices.size();
        if (n < 2)
            return 0;
        int dp[n][2];
        dp[0][0] = 0, dp[0][1] = -prices[0];
        dp[1][0] = std::max(dp[0][0], dp[0][1] + prices[1]);
        dp[1][1] = std::max(dp[0][1], -prices[1]);
        for (int i = 2; i < n; i++) {
            dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = std::max(dp[i - 1][1], dp[i - 2][0] - prices[i]);
        }
        return dp[n - 1][0];
    }
};

// 优化V1
// 压缩空间
class SolutionV2 {
public:
    int maxProfit(std::vector<int> &&prices) {
        int n = prices.size();
        if (n < 2)
            return 0;
        int dp_2_0 = 0, dp_0 = std::max(0, prices[1] - prices[0]), dp_1 = std::max(-prices[0], -prices[1]);
        for (int i = 2; i < n; i++) {
            int last_dp_0 = dp_0;
            dp_0 = std::max(dp_0, dp_1 + prices[i]);
            dp_1 = std::max(dp_1, dp_2_0 - prices[i]);
            dp_2_0 = last_dp_0;
        }
        return dp_0;
    }
};

int main() {
    SolutionV2 s;
    std::cout << s.maxProfit({1, 2, 3, 0, 2}) << std::endl;
    std::cout << s.maxProfit({1}) << std::endl;
    return 0;
}
