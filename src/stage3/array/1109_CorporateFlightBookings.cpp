/**
 * 1109. Corporate Flight Bookings
 * Source: https://leetcode-cn.com/problems/corporate-flight-bookings/
 */

#include <vector>

#include "src/utils/print.h"

// 差分数组
class SolutionV1 {
public:
    std::vector<int> corpFlightBookings(std::vector<std::vector<int>> &bookings, int n) {
        std::vector<int> nums(n, 0), diff(n, 0);
        for (const auto &b: bookings) {
            diff[b[0] - 1] += b[2];
            if (b[1] < n) {
                diff[b[1]] -= b[2];
            }
        }
        nums[0] = diff[0];
        for (int i = 1; i < n; i++)
            nums[i] = nums[i - 1] + diff[i];
        return nums;
    }
};

// 简化V1
class SolutionV2 {
public:
    std::vector<int> corpFlightBookings(std::vector<std::vector<int>> &bookings, int n) {
        std::vector<int> diff(n, 0);
        for (const auto &b: bookings) {
            diff[b[0] - 1] += b[2];
            if (b[1] < n) {
                diff[b[1]] -= b[2];
            }
        }
        for (int i = 1; i < n; i++)
            diff[i] += diff[i - 1];
        return diff;
    }
};

int main() {
    SolutionV2 s;
    std::vector<std::vector<int>> bookings = {{1, 2, 10},
                                              {2, 3, 20},
                                              {2, 5, 25}};
    print_vector(s.corpFlightBookings(bookings, 5));
    bookings = {{1, 2, 10},
                {2, 2, 15}};
    print_vector(s.corpFlightBookings(bookings, 2));
    return 0;
}
