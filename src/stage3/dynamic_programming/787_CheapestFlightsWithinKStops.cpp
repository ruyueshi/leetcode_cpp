/**
 * 787. Cheapest Flights Within K Stops
 * Source: https://leetcode-cn.com/problems/cheapest-flights-within-k-stops/
 */

#include <iostream>
#include <vector>
#include <unordered_map>

// 回溯法超时
class SolutionV1 {
public:
    int findCheapestPrice(int n, std::vector<std::vector<int>> &flights, int src, int dst, int k) {
        std::vector<std::vector<int>> graph(n, std::vector<int>(n, -1));
        for (const auto &path: flights) {
            graph[path[0]][path[1]] = path[2];
        }
        traceback(n, graph, src, dst, k, 0, 0);
        return min_price == INT32_MAX ? -1 : min_price;
    }

private:
    int min_price = INT32_MAX;

    void traceback(int n, const std::vector<std::vector<int>> &graph, int now, int dst, int k, int count, int sum) {
        if (now == dst) {
            min_price = std::min(min_price, sum);
            return;
        }
        if (count > k)
            return;
        for (int j = 0; j < n; j++) {
            if (graph[now][j] > 0) {
                traceback(n, graph, j, dst, k, count + 1, sum + graph[now][j]);
            }
        }
    }
};

// 动态规划
class Solution {
public:
    int findCheapestPrice(int n, std::vector<std::vector<int>> &flights, int src, int dst, int k) {
        std::unordered_map<int, std::vector<std::pair<int, int>>> indegrees;
        std::vector<std::vector<int>> dp(k + 1, std::vector<int>(n, -1));  // dp[i][j]表示i+1步之内，从src到目标j的最小代价

        for (const auto &path: flights) {
            int from = path[0], to = path[1], price = path[2];
            indegrees[to].push_back({from, price});
            if (from == src)
                dp[0][to] = price;
        }
        dp[0][src] = 0;
        for (int i = 1; i <= k; i++) {
            for (int j = 0; j < n; j++) {
                if (j == src) {
                    dp[i][j] = 0;
                    continue;
                }
                int min_price = INT32_MAX;
                for (const auto &from_price: indegrees[j]) {
                    if (dp[i - 1][from_price.first] >= 0)
                        min_price = std::min(min_price, dp[i - 1][from_price.first] + from_price.second);
                }
                dp[i][j] = min_price == INT32_MAX ? -1 : min_price;
            }
        }
        return dp[k][dst];
    }
};

int main() {
    std::vector<std::vector<int>> flights = {{0, 1, 2},
                                             {1, 2, 1},
                                             {2, 0, 10}};
    std::cout << Solution().findCheapestPrice(3, flights, 1, 2, 1) << std::endl;
    flights = {{0, 1, 100},
               {1, 2, 100},
               {2, 0, 100},
               {1, 3, 600},
               {2, 3, 200}};
    std::cout << Solution().findCheapestPrice(4, flights, 0, 3, 1) << std::endl;
    flights = {{0, 1, 100},
               {1, 2, 100},
               {0, 2, 500}};
    std::cout << Solution().findCheapestPrice(3, flights, 0, 2, 1) << std::endl;
    std::cout << Solution().findCheapestPrice(3, flights, 0, 2, 0) << std::endl;
    flights = {{0,  12, 28},
               {5,  6,  39},
               {8,  6,  59},
               {13, 15, 7},
               {13, 12, 38},
               {10, 12, 35},
               {15, 3,  23},
               {7,  11, 26},
               {9,  4,  65},
               {10, 2,  38},
               {4,  7,  7},
               {14, 15, 31},
               {2,  12, 44},
               {8,  10, 34},
               {13, 6,  29},
               {5,  14, 89},
               {11, 16, 13},
               {7,  3,  46},
               {10, 15, 19},
               {12, 4,  58},
               {13, 16, 11},
               {16, 4,  76},
               {2,  0,  12},
               {15, 0,  22},
               {16, 12, 13},
               {7,  1,  29},
               {7,  14, 100},
               {16, 1,  14},
               {9,  6,  74},
               {11, 1,  73},
               {2,  11, 60},
               {10, 11, 85},
               {2,  5,  49},
               {3,  4,  17},
               {4,  9,  77},
               {16, 3,  47},
               {15, 6,  78},
               {14, 1,  90},
               {10, 5,  95},
               {1,  11, 30},
               {11, 0,  37},
               {10, 4,  86},
               {0,  8,  57},
               {6,  14, 68},
               {16, 8,  3},
               {13, 0,  65},
               {2,  13, 6},
               {5,  13, 5},
               {8,  11, 31},
               {6,  10, 20},
               {6,  2,  33},
               {9,  1,  3},
               {14, 9,  58},
               {12, 3,  19},
               {11, 2,  74},
               {12, 14, 48},
               {16, 11, 100},
               {3,  12, 38},
               {12, 13, 77},
               {10, 9,  99},
               {15, 13, 98},
               {15, 12, 71},
               {1,  4,  28},
               {7,  0,  83},
               {3,  5,  100},
               {8,  9,  14},
               {15, 11, 57},
               {3,  6,  65},
               {1,  3,  45},
               {14, 7,  74},
               {2,  10, 39},
               {4,  8,  73},
               {13, 5,  77},
               {10, 0,  43},
               {12, 9,  92},
               {8,  2,  26},
               {1,  7,  7},
               {9,  12, 10},
               {13, 11, 64},
               {8,  13, 80},
               {6,  12, 74},
               {9,  7,  35},
               {0,  15, 48},
               {3,  7,  87},
               {16, 9,  42},
               {5,  16, 64},
               {4,  5,  65},
               {15, 14, 70},
               {12, 0,  13},
               {16, 14, 52},
               {3,  10, 80},
               {14, 11, 85},
               {15, 2,  77},
               {4,  11, 19},
               {2,  7,  49},
               {10, 7,  78},
               {14, 6,  84},
               {13, 7,  50},
               {11, 6,  75},
               {5,  10, 46},
               {13, 8,  43},
               {9,  10, 49},
               {7,  12, 64},
               {0,  10, 76},
               {5,  9,  77},
               {8,  3,  28},
               {11, 9,  28},
               {12, 16, 87},
               {12, 6,  24},
               {9,  15, 94},
               {5,  7,  77},
               {4,  10, 18},
               {7,  2,  11},
               {9,  5,  41}};
    std::cout << Solution().findCheapestPrice(17, flights, 13, 4, 13) << std::endl;
    return 0;
}
