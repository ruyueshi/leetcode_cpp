/**
 * 122. Best Time to Buy and Sell Stock II
 * Source: https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/
 */

#include <iostream>
#include <vector>

class Solution {
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

int main() {
    Solution s;
    std::cout << s.maxProfit({7, 1, 5, 3, 6, 4}) << std::endl;
    std::cout << s.maxProfit({1, 2, 3, 4, 5}) << std::endl;
    std::cout << s.maxProfit({7, 6, 4, 3, 1}) << std::endl;
    return 0;
}
