/**
 * 48. Rotate Image
 * Source: https://leetcode-cn.com/problems/rotate-image/
 */

#include <vector>

#include "src/utils/print.h"

class Solution {
public:
    void rotate(std::vector<std::vector<int>> &matrix) {
        int n = matrix.size();
        for (int i = 0; i <= n / 2; i++) {
            rotate_one_circle(matrix, i, n - 1 - i);
        }
    }

private:
    void rotate_one_circle(std::vector<std::vector<int>> &matrix, int start, int end) {
        if (start == end)
            return;
        for (int i = start; i <= end - 1; i++) {
            int temp1 = matrix[start][i], temp2 = matrix[i][end];
            matrix[i][end] = temp1;
            temp1 = temp2, temp2 = matrix[end][end - (i - start)];
            matrix[end][end - (i - start)] = temp1;
            temp1 = temp2, temp2 = matrix[end - (i - start)][start];
            matrix[end - (i - start)][start] = temp1;
            temp1 = temp2;
            matrix[start][i] = temp1;
        }
    }
};

int main() {
    Solution s;
    std::vector<std::vector<int>> matrix = {{1, 2, 3},
                                            {4, 5, 6},
                                            {7, 8, 9}};
    s.rotate(matrix);
    for (const auto &v: matrix)
        print_vector(v);
    matrix = {{5,  1,  9,  11},
              {2,  4,  8,  10},
              {13, 3,  6,  7},
              {15, 14, 12, 16}};
    s.rotate(matrix);
    for (const auto &v: matrix)
        print_vector(v);
    return 0;
}
