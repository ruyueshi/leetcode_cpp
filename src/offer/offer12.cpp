/**
 * offer 12. 矩阵中的路径
 * Source: https://leetcode-cn.com/problems/ju-zhen-zhong-de-lu-jing-lcof/
 */

#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <tuple>

class Solution {
public:
    bool exist(std::vector<std::vector<char>> &board, std::string word) {
        if (word.length() == 0)
            return false;
        int m = board.size(), n = board[0].size();
        std::queue<std::pair<int, int>> first_points;

        // find the first point
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++)
                if (board[i][j] == word[0])
                    first_points.push({i, j});
        }

        while (!first_points.empty()) {
            auto fp = first_points.front();
            first_points.pop();
            // s: {i, j, k, direction}
            // i,j: 点的坐标
            // k: 当前搜索的字母在word中的位置
            // direction: 当前字母在上一个字母的哪个方向，取值为[-1,3]，
            // -1表示当前字母为起始字母，0,1,2,3分别表示当前字母在上一个字母的上、右、下、左四个方向
            std::stack<std::tuple<int, int, int, int>> s;
            s.push({fp.first, fp.second, 0, -1});
            std::vector<std::pair<int, int>> path;
            while (!s.empty()) {
                auto p = s.top();
                s.pop();
                int i = std::get<0>(p), j = std::get<1>(p), k = std::get<2>(p), direction = std::get<3>(p);
                if (k == word.length() - 1)
                    return true;
                if (k > path.size() - 1) {
                    path.push_back({i, j});
                } else {
                    path.erase(path.begin() + k, path.end());
                    path.push_back({i, j});
                }
                for (int d = 0; d < 4; d++) {  // 搜索上下左右四个方向
                    if (direction != -1 && d == (direction + 2) % 4)  // 保证不搜索原来的方向，防止同一单元格的字母被重复利用
                        continue;
                    int next_i = i, next_j = j;
                    switch (d) {
                        case 0:
                            next_i--;
                            break;
                        case 1:
                            next_j++;
                            break;
                        case 2:
                            next_i++;
                            break;
                        case 3:
                            next_j--;
                            break;
                        default:;
                    }
                    if (judge_edge(next_i, 0, m - 1) && judge_edge(next_j, 0, n - 1)
                        && judge_edge(k + 1, 0, word.length() - 1) && !whether_in_path(path, {next_i, next_j})
                        && board[next_i][next_j] == word[k + 1]) {
                        s.push({next_i, next_j, k + 1, d});
                    }
                }
            }
        }
        return false;
    }

    bool judge_edge(int value, int low, int high) {
        return value >= low && value <= high;
    }

    bool whether_in_path(const std::vector<std::pair<int, int>> &path, const std::pair<int, int> &point) {
        return !(std::find(path.begin(), path.end(), point) == path.end());
    }
};

int main() {
    Solution s;
    std::vector<std::vector<char>> board = {{'A', 'B', 'C', 'E'},
                                            {'S', 'F', 'C', 'S'},
                                            {'A', 'D', 'E', 'E'}};
    std::cout << s.exist(board, "ABCCED") << std::endl;
    board = {{'a', 'b'},
             {'c', 'd'}};
    std::cout << s.exist(board, "abcd") << std::endl;
    board = {{'F', 'Y', 'C', 'E', 'N', 'R', 'D'},
             {'K', 'L', 'N', 'F', 'I', 'N', 'U'},
             {'A', 'A', 'A', 'R', 'A', 'H', 'R'},
             {'N', 'D', 'K', 'L', 'P', 'N', 'E'},
             {'A', 'L', 'A', 'N', 'S', 'A', 'P'},
             {'O', 'O', 'G', 'O', 'T', 'P', 'N'},
             {'H', 'P', 'O', 'L', 'A', 'N', 'O'}};
    std::cout << s.exist(board, "POLAND") << std::endl;
    board = {{'a', 'a', 'a', 'a'},
             {'a', 'a', 'a', 'a'},
             {'a', 'a', 'a', 'a'}};
    std::cout << s.exist(board, "aaaaaaaaaaaaa") << std::endl;
    board = {{'A', 'B', 'C', 'E'},
             {'S', 'F', 'E', 'S'},
             {'A', 'D', 'E', 'E'}};
    std::cout << s.exist(board, "ABCESEEEFS") << std::endl;
    return 0;
}
