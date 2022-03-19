#include <iostream>
#include <vector>
#include <climits>

int N;
std::vector<int> nodes;

int traceback(int root_index, int left_edge, int right_edge) {
    int min_left = INT_MAX, min_right = INT_MAX;

    // 寻找左子树的最小开销
    for (int i = left_edge; i <= root_index - 1; i++) {
        min_left = std::min(min_left, nodes[root_index] * nodes[i] + traceback(i, left_edge, root_index - 1));
    }

    // 寻找右子树的最小开销
    for (int i = root_index + 1; i <= right_edge; i++) {
        min_right = std::min(min_right, nodes[root_index] * nodes[i] + traceback(i, root_index + 1, right_edge));
    }

    return (min_left == INT_MAX ? 0 : min_left) + (min_right == INT_MAX ? 0 : min_right);
}

int get_best_tree() {
    int res = INT_MAX;
    for (int i = 0; i < N; i++) {
        res = std::min(res, traceback(i, 0, N - 1));
    }
    return res;
}

int main() {
    std::cin >> N;
    nodes.resize(N);
    for (int i = 0; i < N; i++)
        std::cin >> nodes[i];
    std::cout << get_best_tree() << std::endl;
    return 0;
}
