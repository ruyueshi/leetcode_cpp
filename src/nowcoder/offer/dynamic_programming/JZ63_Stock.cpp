/**
 * JZ63 买卖股票的最好时机(一)
 * Source: https://www.nowcoder.com/practice/64b4262d4e6d4f6181cd45446a5821ec?tpId=13&tqId=625&ru=/exam/oj/ta&qru=/ta/coding-interviews/question-ranking&sourceUrl=%2Fexam%2Foj%2Fta%3Fpage%3D1%26tpId%3D13%26type%3D13
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param prices int整型vector
     * @return int整型
     */
    int maxProfit(std::vector<int> &prices) {
        // write code here
        int n = prices.size();
        if (n == 0) {
            return 0;
        }
        int min_price = prices[0];
        int max_profit = 0;
        for (int i = 1; i < n; i++) {
            if (prices[i] < min_price) {
                min_price = prices[i];
            } else {
                max_profit = std::max(max_profit, prices[i] - min_price);
            }
        }
        return max_profit;
    }
};

int main() {
    std::vector<int> prices = {8, 9, 2, 5, 4, 7, 1};
    std::cout << Solution().maxProfit(prices) << std::endl;
    return 0;
}