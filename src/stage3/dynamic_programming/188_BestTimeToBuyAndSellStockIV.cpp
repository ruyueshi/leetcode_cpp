/**
 * 188. Best Time to Buy and Sell Stock IV
 * Source: https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/
 */

#include <iostream>
#include <vector>

// 三维动态规划
class SolutionV1 {
public:
    int maxProfit(int k, std::vector<int> &&prices) {
        int n = prices.size();
        if (n == 0 || k == 0)
            return 0;
        int dp[n][k + 1][2];  // 第i天最大交易次数限制为k时持有股票或者不持有股票的最大利润

        // 初始化
        for (int j = 0; j <= k; j++) {
            dp[0][j][0] = 0;  // 持有股票
            dp[0][j][1] = -prices[0];  // 不持有股票
        }
        for (int i = 0; i < n; i++) {
            dp[i][0][0] = 0;
            dp[i][0][1] = INT_MIN;  // 不知道前i天的哪一天买入，所以可以取最小值
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= k; j++) {
                // 第i天不持有股票，且最大交易次数为j
                // std::max(现在不持有股票并且前一天也不持有股票, 前一天持有股票且今天把股票卖了)
                dp[i][j][0] = std::max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i]);
                // 第i天持有股票，且最大交易次数为j
                // std::max(现在持有股票并且前一天也持有股票, 前一天不持有股票（前一天的最大交易次数限制为j-1）且今天买入股票)
                // 注意体会此处j-1的含义，j为最大交易次数限制，而不是已经交易的次数！故如果今天可以买入，那么交易次数限制会比昨天+1
                dp[i][j][1] = std::max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]);
            }
        }

        return dp[n - 1][k][0];
    }
};

// // 优化V1
// // 压缩空间
// class SolutionV2 {
// public:
//     int maxProfit(int k, std::vector<int> &&prices) {
//         int n = prices.size();
//         if (n == 0 || k == 0)
//             return 0;
//
//         int dp_ij_0[k + 1], dp_ij_1[k + 1], dp_ij1_0[k + 1];
//         for (int j = 0; j <= k; j++) {
//             dp_ij_0[j] = 0;
//             dp_ij_1[j] = -prices[0];
//             dp_ij1_0[j] = 0;
//         }
//         for (int i = 1; i < n; i++) {
//             int last_j = dp_ij1_0[0];
//             for (int j = 1; j <= k; j++) {
//                 // 第i天不持有股票，且最大交易次数为j
//                 // std::max(现在不持有股票并且前一天也不持有股票, 前一天持有股票且今天把股票卖了)
//                 dp_ij_0[j] = std::max(dp_ij_0[j], dp_ij_1[j] + prices[i]);
//                 // 第i天持有股票，且最大交易次数为j
//                 // std::max(现在持有股票并且前一天也持有股票, 前一天不持有股票（前一天的最大交易次数限制为j-1）且今天买入股票)
//                 // 注意体会此处j-1的含义，j为最大交易次数限制，而不是已经交易的次数！故如果今天可以买入，那么交易次数限制会比昨天+1
//                 dp_ij_1[j] = std::max(dp_ij_1[j], dp_ij1_0[j - 1] - prices[i]);
//                 dp_ij1_0[j - 1] = last_j;
//                 last_j = dp_ij_0[j];
//             }
//         }
//
//         return dp_ij_0[0];
//     }
// };

int main() {
    SolutionV1 s;
    std::cout << s.maxProfit(2, {2, 4, 1}) << std::endl;
    std::cout << s.maxProfit(2, {3, 2, 6, 5, 0, 3}) << std::endl;
    return 0;
}
