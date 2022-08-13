/**
 * JZ47 礼物的最大价值
 * Source: https://www.nowcoder.com/practice/2237b401eb9347d282310fc1c3adb134?tpId=13&tqId=2276652&ru=/exam/oj/ta&qru=/ta/coding-interviews/question-ranking&sourceUrl=%2Fexam%2Foj%2Fta%3Fpage%3D1%26tpId%3D13%26type%3D13
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
     * @param grid int整型vector<vector<>>
     * @return int整型
     */
    int maxValue(vector<vector<int> > &grid) {
        // write code here
        int m = grid.size();
        int n = grid[0].size();
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1));
        dp[1][1] = grid[0][0];
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1];
            }
        }
        return dp[m][n];
    }
};

int main() {

    return 0;
}