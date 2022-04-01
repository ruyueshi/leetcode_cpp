/**
 * 54. Spiral Matrix
 * Source: https://leetcode-cn.com/problems/spiral-matrix/
 */

#include <algorithm>
#include <vector>

#include "src/utils/print.h"

class Solution {
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>> &matrix) {
        m = matrix.size(), n = matrix[0].size();
        get_one_circle(matrix, 0, 0);
        return path;
    }

private:
    int m, n;
    std::vector<int> path;

    void get_one_circle(std::vector<std::vector<int>> &matrix, int start_row, int start_col) {
        if (start_row > (m - 1) / 2 || start_col > (n - 1) / 2)
            return;
        int end_row = m - 1 - start_row, end_col = n - 1 - start_col;
        for (int j = start_col; j <= end_col; j++)
            path.push_back(matrix[start_row][j]);
        for (int i = start_row + 1; i <= end_row; i++)
            path.push_back(matrix[i][end_col]);
        if (end_row == start_row || end_col == start_col)
            return;
        for (int j = end_col - 1; j >= start_col; j--)
            path.push_back(matrix[end_row][j]);
        for (int i = end_row - 1; i > start_row; i--)
            path.push_back(matrix[i][start_col]);
        get_one_circle(matrix, start_row + 1, start_col + 1);
    }
};

int main() {
    std::vector<std::vector<int>> matrix = {{1, 2, 3},
                                            {4, 5, 6},
                                            {7, 8, 9}};
    print_vector(Solution().spiralOrder(matrix));
    matrix = {{1, 2,  3,  4},
              {5, 6,  7,  8},
              {9, 10, 11, 12}};
    print_vector(Solution().spiralOrder(matrix));

    matrix = {{1,  11},
              {2,  12},
              {3,  13},
              {4,  14},
              {5,  15},
              {6,  16},
              {7,  17},
              {8,  18},
              {9,  19},
              {10, 20}};
    print_vector(Solution().spiralOrder(matrix));
    return 0;
}
