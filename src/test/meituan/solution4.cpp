/*
链接：https://www.nowcoder.com/questionTerminal/0d939e874a004f449a370aca1346dd5c
来源：牛客网
小团有一个由N个节点组成的二叉树，每个节点有一个权值。定义二叉树每条边的开销为其两端节点权值的乘积，
二叉树的总开销即每条边的开销之和。小团按照二叉树的中序遍历依次记录下每个节点的权值，即他记录下了N
个数，第i个数表示位于中序遍历第i个位置的节点的权值。之后由于某种原因，小团遗忘了二叉树的具体结构。
在所有可能的二叉树中，总开销最小的二叉树被称为最优二叉树。现在，小团请小美求出最优二叉树的总开销。

输入描述:
第一行输入一个整数N（1<=N<=300），表示二叉树的节点数。
第二行输入N个由空格隔开的整数，表示按中序遍历记录下的各个节点的权值，所有权值均为不超过1000的正整数。

输出描述:
输出一个整数，表示最优二叉树的总开销。

示例1
输入
5
7 6 5 1 3
输出
45
 */

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
