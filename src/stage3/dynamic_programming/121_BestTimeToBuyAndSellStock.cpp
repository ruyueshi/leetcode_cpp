/**
 * 121. Best Time to Buy and Sell Stock
 * Source: https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/
 */

#include <iostream>
#include <vector>

// 动态规划
class SolutionV1 {
public:
    int maxProfit(std::vector<int> &&prices) {
        if (prices.size() < 2)
            return 0;
        std::vector<int> dp(prices.size(), 0);
        int min_price = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            dp[i] = std::max(dp[i - 1], prices[i] - min_price);
            min_price = std::min(min_price, prices[i]);
        }
        return dp.back();
    }
};

// 优化V1
class SolutionV2 {
public:
    int maxProfit(std::vector<int> &&prices) {
        if (prices.size() < 2)
            return 0;
        int min_price = prices[0], max_profit = 0;  // min_price max_profit分别表示前i天里股票最低价格和能交易的最大利润
        for (int i = 1; i < prices.size(); i++) {
            max_profit = std::max(max_profit, prices[i] - min_price);
            min_price = std::min(min_price, prices[i]);
        }
        return max_profit;
    }
};

// 完全动态规划：
class SolutionV3 {
public:
    int maxProfit(std::vector<int> &&prices) {
        int n = prices.size();
        int dp[n][2];
        dp[0][0] = 0, dp[0][1] = -prices[0];
        for (int i = 1; i < n; i++) {
            // 第i天不持有股票
            dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][1] + prices[i]);  // std::max(现在不持有股票并且前一天也不持有股票, 前一天持有股票且今天把股票卖了)
            // 第i天持有股票
            dp[i][1] = std::max(dp[i - 1][1], -prices[i]);  // std::max(现在持有股票并且前一天也持有股票, 前一天不持有股票且今天买入股票)
        }
        return dp[n - 1][0];  // 最后一天手里应当不持有股票
    }
};

// 优化V3
class SolutionV4 {
public:
    int maxProfit(std::vector<int> &&prices) {
        int dp_i_0 = 0, dp_i_1 = -prices[0];
        for (int i = 1; i < prices.size(); i++) {
            // 第i天不持有股票
            dp_i_0 = std::max(dp_i_0, dp_i_1 + prices[i]);  // std::max(现在不持有股票并且前一天也不持有股票, 前一天持有股票且今天把股票卖了)
            // 第i天持有股票
            dp_i_1 = std::max(dp_i_1, -prices[i]);  // std::max(现在持有股票并且前一天也持有股票, 前一天不持有股票且今天买入股票)
        }
        return dp_i_0;  // 最后一天手里应当不持有股票
    }
};

int main() {
    SolutionV4 s;
    std::cout << s.maxProfit({2, 4, 1}) << std::endl;
    std::cout << s.maxProfit({3, 2, 6, 5, 0, 3}) << std::endl;
    std::cout << s.maxProfit({7, 1, 5, 3, 6, 4}) << std::endl;
    return 0;
}
