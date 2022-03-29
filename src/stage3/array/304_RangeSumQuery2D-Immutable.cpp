/**
 * 304. Range Sum Query 2D - Immutable
 * Source: https://leetcode-cn.com/problems/range-sum-query-2d-immutable/
 */

#include <iostream>
#include <vector>

class NumMatrix {
public:
    NumMatrix(std::vector<std::vector<int>> &matrix) : pre_sum(matrix.size() + 1, std::vector<int>(matrix[0].size() + 1, 0)) {
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                pre_sum[i][j] = pre_sum[i - 1][j] + pre_sum[i][j - 1] - pre_sum[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return pre_sum[row2 + 1][col2 + 1] - pre_sum[row2 + 1][col1] - pre_sum[row1][col2 + 1] + pre_sum[row1][col1];
    }

private:
    std::vector<std::vector<int>> pre_sum;
};

int main() {
    std::vector<std::vector<int>> matrix = {{3, 0, 1, 4, 2},
                                            {5, 6, 3, 2, 1},
                                            {1, 2, 0, 1, 5},
                                            {4, 1, 0, 1, 7},
                                            {1, 0, 3, 0, 5}};
    NumMatrix n(matrix);
    std::cout << n.sumRegion(0, 0, 1, 1) << std::endl;
    std::cout << n.sumRegion(2, 1, 4, 3) << std::endl;
    std::cout << n.sumRegion(1, 1, 2, 2) << std::endl;
    std::cout << n.sumRegion(1, 2, 2, 4) << std::endl;
    return 0;
}
