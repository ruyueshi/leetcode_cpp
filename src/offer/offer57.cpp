/**
 * offer 57. 和为s的两个数字
 * Source: https://leetcode-cn.com/problems/he-wei-sde-liang-ge-shu-zi-lcof/
 */

#include <vector>
#include "src/utils/print.h"

class Solution {
public:
    // 时间复杂度O(N), 空间复杂度O(1)
    std::vector<int> twoSum(std::vector<int> &nums, int target) {
        int low = 0, high = nums.size() - 1;
        while (low < high) {
            int sum = nums[low] + nums[high];
            if (sum < target)
                low++;
            else if (sum > target)
                high--;
            else
                return {nums[low], nums[high]};
        }
        return std::vector<int>();
    }
};

int main() {
    Solution s;
    std::vector<int> v = {10, 26, 30, 31, 47, 60};
    std::vector<int> res = s.twoSum(v, 40);
    print_vector(res);
    v = {2, 7, 11, 15};
    res = s.twoSum(v, 9);
    print_vector(res);
    return 0;
}
