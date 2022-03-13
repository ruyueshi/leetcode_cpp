/**
 * 122. Best Time to Buy and Sell Stock II
 * Source: https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/
 */

#include <iostream>
#include <vector>

class SolutionV1 {
public:
    int maxProfit(std::vector<int> &&prices) {
        int cur_min = prices[0], max_profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > cur_min) {
                max_profit = max_profit + (prices[i] - cur_min);

            }
            cur_min = prices[i];
        }
        return max_profit;
    }
};

// 完全动态规划：
// k = 无穷大 (k为最大交易次数)
class SolutionV2 {
public:
    int maxProfit(std::vector<int> &&prices) {
        int n = prices.size();
        int dp[n][2];
        dp[0][0] = 0, dp[0][1] = -prices[0];
        for (int i = 1; i < n; i++) {
            // 第i天不持有股票
            dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][1] + prices[i]);  // std::max(现在不持有股票并且前一天也不持有股票, 前一天持有股票且今天把股票卖了)
            // 第i天持有股票
            dp[i][1] = std::max(dp[i - 1][1], dp[i - 1][0] - prices[i]);  // std::max(现在持有股票并且前一天也持有股票, 前一天不持有股票且今天买入股票)
        }
        return dp[n - 1][0];  // 最后一天手里应当不持有股票
    }
};

// 优化V3
// 压缩空间
class SolutionV3 {
public:
    int maxProfit(std::vector<int> &&prices) {
        int dp_i_0 = 0, dp_i_1 = -prices[0];
        for (int i = 1; i < prices.size(); i++) {
            int temp = dp_i_0;
            // 第i天不持有股票
            dp_i_0 = std::max(dp_i_0, dp_i_1 + prices[i]);  // std::max(现在不持有股票并且前一天也不持有股票, 前一天持有股票且今天把股票卖了)
            // 第i天持有股票
            dp_i_1 = std::max(dp_i_1, temp - prices[i]);  // std::max(现在持有股票并且前一天也持有股票, 前一天不持有股票且今天买入股票)
        }
        return dp_i_0;  // 最后一天手里应当不持有股票
    }
};

int main() {
    SolutionV3 s;
    std::cout << s.maxProfit({7, 1, 5, 3, 6, 4}) << std::endl;
    std::cout << s.maxProfit({1, 2, 3, 4, 5}) << std::endl;
    std::cout << s.maxProfit({7, 6, 4, 3, 1}) << std::endl;
    return 0;
}
