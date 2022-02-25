/**
 * 322. Coin Change
 * Source: https://leetcode-cn.com/problems/coin-change/
 */

#include <iostream>
#include <vector>

class Solution {
public:
    int coinChange(std::vector<int> &coins, int amount) {
        std::vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (i - coins[j] < 0)
                    continue;
                dp[i] = std::min(dp[i], 1 + dp[i - coins[j]]);
            }
        }
        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};

int main() {
    Solution s;
    std::vector<int> coins = {1, 2, 5};
    std::cout << s.coinChange(coins, 11) << std::endl;
    return 0;
}

