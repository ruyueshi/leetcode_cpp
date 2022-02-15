/**
 * offer 63. 股票的最大利润
 * Source: https://leetcode-cn.com/problems/gu-piao-de-zui-da-li-run-lcof/
 */

#include <iostream>
#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int> &prices) {
        if (prices.size() <= 1)
            return 0;
        int min_price = prices[0], cur = 0;  // min_price表示前i天里最小的股票价格
        for (size_t i = 1; i < prices.size(); i++) {
            cur = std::max(cur, (prices[i] - min_price));
            min_price = std::min(min_price, prices[i]);
        }
        return cur;
    }
};

int main() {
    Solution s;
    std::vector<int> a = {7, 1, 5, 3, 6, 4};
    std::cout << s.maxProfit(a) << std::endl;
    a = {7, 6, 5, 4, 3, 2, 1};
    std::cout << s.maxProfit(a) << std::endl;
    return 0;
}