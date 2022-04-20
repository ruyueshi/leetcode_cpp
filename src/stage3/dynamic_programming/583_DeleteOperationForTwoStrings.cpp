/**
 * 583. Delete Operation for Two Strings
 * Source: https://leetcode-cn.com/problems/delete-operation-for-two-strings/
 */

#include <iostream>
#include <string>
#include <vector>

// V1：直接解
class SolutionV1 {
public:
    int minDistance(std::string word1, std::string word2) {
        int m = word1.length(), n = word2.length();
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1));
        for (int i = 1; i <= m; i++)
            dp[i][0] = i;
        for (int j = 1; j <= n; j++)
            dp[0][j] = j;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = std::min(dp[i-1][j], dp[i][j-1]) + 1;
                }
            }
        }
        return dp[m][n];
    }
};

// V2：借助最长公共子序列间接求解
// 先求word1和word2的最长公共子序列lcs，那最小删除数就是word1.length() - lcs + word2.length() - lcs
class SolutionV2 {
public:
    int minDistance(std::string word1, std::string word2) {
        int m = word1.length(), n = word2.length();
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        int lcs = dp[m][n];
        return (m - lcs) + (n - lcs);
    }
};

int main() {
    SolutionV2 s;
    std::cout << s.minDistance("sea", "eat") << std::endl;
    std::cout << s.minDistance("leetcode", "etco") << std::endl;
    return 0;
}
