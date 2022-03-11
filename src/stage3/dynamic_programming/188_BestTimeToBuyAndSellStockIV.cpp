/**
 * 188. Best Time to Buy and Sell Stock IV
 * Source: https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/
 */

#include <iostream>
#include <vector>

class Solution {
public:
    int maxProfit(int k, std::vector<int> &&prices) {
        int a = 6;
        prices.push_back(4);
        prices.push_back(a);
        prices.emplace_back(4);
    }
};

int main() {
    Solution s;
    std::cout << s.maxProfit(2, {2, 4, 1}) << std::endl;
    std::cout << s.maxProfit(2, {3, 2, 6, 5, 0, 3}) << std::endl;
    return 0;
}
