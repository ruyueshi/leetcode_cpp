#include <iostream>
#include <vector>
#include <climits>
#include "memory.h"

#define MAX_N 301

typedef std::vector<std::vector<std::vector<int>>> threeD_array;
typedef std::vector<std::vector<int>> twoD_array;

int N;
// std::vector<int> nodes;
int nodes[MAX_N];
int dp[MAX_N][MAX_N][MAX_N];

int traceback(int root_index, int left_edge, int right_edge) {
    if (left_edge > right_edge)
        return 0;
    if (dp[root_index][left_edge][right_edge] != -1)
        return dp[root_index][left_edge][right_edge];

    int res = INT_MAX;
    for (int i = left_edge; i <= right_edge; i++) {
        int min_left = traceback(i, left_edge, i - 1);
        int min_right = traceback(i, i + 1, right_edge);
        res = std::min(res, min_left + min_right + nodes[i] * nodes[root_index]);
    }
    dp[root_index][left_edge][right_edge] = res;
    return res;
}

int main() {
    std::cin >> N;
    // nodes.resize(N + 1);
    nodes[0] = 0;
    for (int i = 1; i <= N; i++)
        std::cin >> nodes[i];
    // threeD_array dp(N + 1, twoD_array(N + 1, std::vector<int>(N + 1, -1)));  // dp[i][j][k] 表示以i为根节点、j-k为子树节点时的最小开销
    memset(dp, -1, sizeof dp);
    std::cout << traceback(0, 1, N) << std::endl;  // 0为虚拟节点
    return 0;
}
