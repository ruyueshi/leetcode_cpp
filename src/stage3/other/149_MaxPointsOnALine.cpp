/**
 * 149. Max Points on a Line
 * Source: https://leetcode-cn.com/problems/max-points-on-a-line/
 */

#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    int maxPoints(std::vector<std::vector<int>> &points) {
        int n = points.size();
        int max_count = 1;
        for (int i = 0; i < n; i++) {
            std::unordered_map<double, int> m;
            int count_infinity = 0;
            for (int j = i + 1; j < n; j++) {
                if (points[i][0] == points[j][0]) {
                    count_infinity++;
                } else {
                    double k = double(points[j][1] - points[i][1]) / (points[j][0] - points[i][0]);
                    m[k]++;
                }
            }
            int row_max_count = count_infinity;
            for (const auto &it: m)
                row_max_count = std::max(row_max_count, it.second);
            max_count = std::max(max_count, row_max_count + 1);
        }
        return max_count;
    }
};

int main() {
    Solution s;
    std::vector<std::vector<int>> v = {{1, 1},
                                       {3, 2},
                                       {5, 3},
                                       {4, 1},
                                       {2, 3},
                                       {1, 4}};
    std::cout << s.maxPoints(v) << std::endl;
    v = {{0, 0},
         {4, 5},
         {7, 8},
         {8, 9},
         {5, 6},
         {3, 4},
         {1, 1}};
    std::cout << s.maxPoints(v) << std::endl;
    return 0;
}
