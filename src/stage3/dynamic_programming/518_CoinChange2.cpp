/**
 * 518. Coin Change 2
 * Source: https://leetcode-cn.com/problems/coin-change-2/
 */

#include <iostream>
#include <vector>

class Solution {
public:
    int change(int amount, std::vector<int> &coins) {
        int n = coins.size();
        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(amount + 1, 0));
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= amount; j++) {
                if (coins[i - 1] <= j) {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][amount];
    }

    // 压缩空间
    int change_v2(int amount, std::vector<int> &coins) {
        int n = coins.size();
//        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(amount + 1, 0));
//        for (int i = 0; i <= n; i++) {
//            dp[i][0] = 1;
//        }

        std::vector<int> dp(amount + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= amount; j++) {
                if (coins[i - 1] <= j) {
                    dp[j] = dp[j] + dp[j - coins[i - 1]];
                } else {
                    dp[j] = dp[j];
                }
            }
        }

        return dp[amount];
    }
};

int main() {
    Solution s;
    std::vector<int> coins = {1, 2, 5};
    std::cout << s.change(5, coins) << std::endl;
    coins = {1, 2, 3};
    std::cout << s.change(20, coins) << std::endl;
    return 0;
}
