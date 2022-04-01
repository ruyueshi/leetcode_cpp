/**
 * 59. Spiral Matrix II
 * Source: https://leetcode-cn.com/problems/spiral-matrix-ii/
 */

#include <algorithm>
#include <vector>

#include "src/utils/print.h"

class Solution {
public:
    std::vector<std::vector<int>> generateMatrix(int n) {
        std::vector<std::vector<int>> matrix(n, std::vector<int>(n, 0));
        int val = 1;
        int left_bound = 0, right_bound = n - 1, up_round = 0, down_round = n - 1;
        while (val <= n*n) {
            // 从左往右遍历
            if (up_round <= down_round) {
                for (int j = left_bound; j <= right_bound; j++)
                    matrix[up_round][j] = val++;
                up_round++;
            }
            // 从上往下遍历
            if (left_bound <= right_bound) {
                for (int i = up_round; i <= down_round; i++)
                    matrix[i][right_bound] = val++;
                right_bound--;
            }
            // 从右往左遍历
            if (up_round <= down_round) {
                for (int j = right_bound; j >= left_bound; j--)
                    matrix[down_round][j] = val++;
                down_round--;
            }
            // 从下往上遍历
            if (left_bound <= right_bound) {
                for (int i = down_round; i >= up_round; i--)
                    matrix[i][left_bound] = val++;
                left_bound++;
            }
        }
        return matrix;
    }
};

int main() {
    auto res = Solution().generateMatrix(3);
    for (const auto &v: res)
        print_vector(v);
    res = Solution().generateMatrix(4);
    for (const auto &v: res)
        print_vector(v);
    return 0;
}
