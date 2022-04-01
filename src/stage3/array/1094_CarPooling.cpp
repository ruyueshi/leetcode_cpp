/**
 * 1109. Corporate Flight Bookings
 * Source: https://leetcode-cn.com/problems/car-pooling/
 */

#include <iostream>
#include <vector>

// 差分数组
class Solution {
public:
    bool carPooling(std::vector<std::vector<int>> &trips, int capacity) {
        int n = 1001, max_length = 0;
        std::vector<int> diff(n, 0);
        for (const auto &t: trips) {
            int i = t[1], j = t[2], val = t[0];
            diff[i] += val;
            if (j < 1001)  // 注意此处不是j+1，因为乘客在j处下车
                diff[j] -= val;
            max_length = std::max(j, max_length);
        }
        for (int i = 1; i <= max_length; i++) {
            diff[i] += diff[i - 1];
            if (diff[i] > capacity)
                return false;
        }
        return true;
    }
};

int main() {
    Solution s;
    std::vector<std::vector<int>> trips = {{2, 1, 5},
                                           {3, 3, 7}};
    std::cout << s.carPooling(trips, 4) << std::endl;
    std::cout << s.carPooling(trips, 5) << std::endl;
    return 0;
}
