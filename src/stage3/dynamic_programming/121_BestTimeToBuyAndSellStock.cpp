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
            dp[i] = std::max(dp[i-1], prices[i] - min_price);
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

int main() {
    SolutionV2 s;
    std::cout << s.maxProfit({2, 4, 1}) << std::endl;
    std::cout << s.maxProfit({3, 2, 6, 5, 0, 3}) << std::endl;
    return 0;
}
