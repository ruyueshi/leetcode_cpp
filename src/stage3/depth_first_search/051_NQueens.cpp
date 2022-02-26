/**
 * 51. N-Queens
 * Source: https://leetcode-cn.com/problems/n-queens/
 */

#include <iostream>
#include <vector>
#include <string>

#include "src/utils/print.h"

class Solution {
public:
    std::vector<std::vector<std::string>> solveNQueens(int n) {
        std::vector<std::string> board(n, std::string(n, '.'));
        backtrack(board, 0, n);
        return this->res;
    }

private:
    std::vector<std::vector<std::string>> res;

    void backtrack(std::vector<std::string> &board, int row, int n) {
        if (row == n) {
            this->res.push_back(board);
            return;
        }
        for (int col = 0; col < n; col++) {
            if (isValid(board, row, col, n)) {
                board[row][col] = 'Q';
                backtrack(board, row + 1, n);
                board[row][col] = '.';
            }
        }
    }

    bool isValid(const std::vector<std::string> &board, int row, int col, int n) {
        for (int i = 0; i < row; i++) {
            // 检查列
            if (board[i][col] == 'Q')
                return false;

            // 检查左上
            int temp_col = col - (row - i);
            if (temp_col >= 0 && board[i][temp_col] == 'Q')
                return false;

            // 检查右上
            temp_col = col + (row - i);
            if (temp_col < n && board[i][temp_col] == 'Q')
                return false;
        }
        return true;
    }
};

int main() {
    Solution s;
    auto res = s.solveNQueens(4);
    std::cout << "result num: " << res.size() << std::endl;
    for (const auto &v: res)
        print_vector(v);
    return 0;
}
