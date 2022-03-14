/**
 * 714. Best Time to Buy and Sell Stock with Transaction Fee
 * Source: https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
 */

#include <iostream>
#include <vector>

// 待条件的动态规划
class SolutionV1 {
public:
    int maxProfit(std::vector<int> &&prices, int fee) {
        int n = prices.size();
        int dp[n][2];
        dp[0][0] = 0, dp[0][1] = -prices[0];
        for (int i = 1; i < n; i++) {
            dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][1] + prices[i] - fee);
            dp[i][1] = std::max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }
        return dp[n - 1][0];
    }
};

// 优化V1
// 压缩空间
class SolutionV2 {
public:
    int maxProfit(std::vector<int> &&prices, int fee) {
        int n = prices.size();
        int dp_i_0 = 0, dp_i_1 = -prices[0];
        for (int i = 1; i < n; i++) {
            int temp = dp_i_0;
            dp_i_0 = std::max(dp_i_0, dp_i_1 + prices[i] - fee);
            dp_i_1 = std::max(dp_i_1, temp - prices[i]);
        }
        return dp_i_0;
    }
};

int main() {
    SolutionV2 s;
    std::cout << s.maxProfit({1, 3, 2, 8, 4, 9}, 2) << std::endl;
    std::cout << s.maxProfit({1, 3, 7, 5, 10, 3}, 3) << std::endl;
    return 0;
}
