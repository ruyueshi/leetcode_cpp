/**
 * 130. Surrounded Regions
 * Source: https://leetcode-cn.com/problems/surrounded-regions/
 */

#include <vector>

#include "src/utils/print.h"

class SolutionV1 {
public:
    void solve(std::vector<std::vector<char>> &board) {
        M = board.size(), N = board[0].size();
        for (int i = 0; i < M; i++) {
            if (board[i][0] == 'O')
                dfs(board, i, 0, 'O', '#');
            if (board[i][N - 1] == 'O')
                dfs(board, i, N - 1, 'O', '#');
        }
        for (int j = 0; j < N; j++) {
            if (board[0][j] == 'O')
                dfs(board, 0, j, 'O', '#');
            if (board[M - 1][j] == 'O')
                dfs(board, M - 1, j, 'O', '#');
        }

        for (int i = 1; i < M - 1; i++) {
            for (int j = 1; j < N - 1; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }

        for (int i = 0; i < M; i++) {
            if (board[i][0] == '#')
                dfs(board, i, 0, '#', 'O');
            if (board[i][N - 1] == '#')
                dfs(board, i, N - 1, '#', 'O');
        }
        for (int j = 0; j < N; j++) {
            if (board[0][j] == '#')
                dfs(board, 0, j, '#', 'O');
            if (board[M - 1][j] == '#')
                dfs(board, M - 1, j, '#', 'O');
        }
    }

private:
    int M, N;
    std::vector<std::vector<int>> direction = {{-1, 0},
                                               {0,  1},
                                               {1,  0},
                                               {0,  -1}};

    void dfs(std::vector<std::vector<char>> &board, int i, int j, char source, char target) {
        if (i < 0 || i >= M || j < 0 || j >= N || board[i][j] == 'X')
            return;
        if (board[i][j] == target)
            return;
        board[i][j] = target;
        for (int k = 0; k < 4; k++) {
            dfs(board, i + direction[k][0], j + direction[k][1], source, target);
        }
    }
};

class SolutionV2 {
public:
    void solve(std::vector<std::vector<char>> &board) {
        M = board.size(), N = board[0].size();
        for (int i = 0; i < M; i++) {
            if (board[i][0] == 'O')
                dfs(board, i, 0);
            if (board[i][N - 1] == 'O')
                dfs(board, i, N - 1);
        }
        for (int j = 0; j < N; j++) {
            if (board[0][j] == 'O')
                dfs(board, 0, j);
            if (board[M - 1][j] == 'O')
                dfs(board, M - 1, j);
        }

        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }

private:
    int M, N;
    std::vector<std::vector<int>> direction = {{-1, 0},
                                               {0,  1},
                                               {1,  0},
                                               {0,  -1}};

    void dfs(std::vector<std::vector<char>> &board, int i, int j) {
        if (i < 0 || i >= M || j < 0 || j >= N || board[i][j] == 'X' || board[i][j] == '#')
            return;
        board[i][j] = '#';
        for (int k = 0; k < 4; k++)
            dfs(board, i + direction[k][0], j + direction[k][1]);
    }
};

int main() {
    SolutionV2 s;
    std::vector<std::vector<char>> board = {{'X', 'X', 'X', 'X'},
                                            {'X', 'O', 'O', 'X'},
                                            {'X', 'X', 'O', 'X'},
                                            {'X', 'O', 'X', 'X'}};
    s.solve(board);
    for (auto &v: board)
        print_vector(v);
    board = {{'O', 'O'},
             {'O', 'O'}};
    s.solve(board);
    for (auto &v: board)
        print_vector(v);
    return 0;
}
