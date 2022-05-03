/**
 * 514. Freedom Trail
 * Source: https://leetcode-cn.com/problems/freedom-trail/
 */

#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    int findRotateSteps(std::string ring, std::string key) {
        int m = ring.size(), n = key.size();
        std::unordered_map<char, std::vector<int>> index;
        for (int i = 0; i < m; i++) {
            index[ring[i]].push_back(i);
        }

        std::vector<std::vector<int>> dp(m, std::vector<int>(n + 1));  // dp[i][j]表示ring[i]指向12:00方向时，拼写key[j...n-1]的最小操作数

        for (int j = n - 1; j >= 0; j--) {
            for (int i = 0; i < m; i++) {
                int min_ops = INT32_MAX;
                for (const auto &k : index[key[j]]) {
                    int step = std::min(std::abs(i - k), std::abs(m - std::abs(i - k)));
                    min_ops = std::min(min_ops, step + 1 + dp[k][j + 1]);
                }
                dp[i][j] = min_ops;
            }
        }

        return dp[0][0];
    }
};

int main() {
    Solution s;
    std::cout << s.findRotateSteps("ababcab", "acbaacba") << std::endl;
    std::cout << s.findRotateSteps("godding", "gd") << std::endl;
    std::cout << s.findRotateSteps("godding", "godding") << std::endl;
    return 0;
}
