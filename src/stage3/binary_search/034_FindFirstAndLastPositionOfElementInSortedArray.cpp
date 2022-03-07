/**
 * 34. Find First and Last Position of Element in Sorted Array
 * Source: https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/
 */

#include <vector>

#include "src/utils/print.h"

class Solution {
public:
    std::vector<int> searchRange(std::vector<int> &nums, int target) {
        if (nums.empty())
            return {-1, -1};
        int left1 = 0, right1 = nums.size() - 1, left2 = left1, right2 = right1;
        while (left1 <= right1 || left2 <= right2) {
            int mid1 = left1 + (right1 - left1) / 2;
            int mid2 = left2 + (right2 - left2) / 2;
            if (left1 <= right1) {
                if (nums[mid1] == target) {
                    right1 = mid1 - 1;
                } else if (nums[mid1] > target) {
                    right1 = mid1 - 1;
                } else {
                    left1 = mid1 + 1;
                }
            }
            if (left2 <= right2) {
                if (nums[mid2] == target) {
                    left2 = mid2 + 1;
                } else if (nums[mid2] > target) {
                    right2 = mid2 - 1;
                } else {
                    left2 = mid2 + 1;
                }
            }
        }
        int res1 = left1 >= nums.size() || nums[left1] != target ? -1 : left1;
        int res2 = right2 >= nums.size() || nums[right2] != target ? -1 : right2;
        return {res1, res2};
    }
};

int main() {
    Solution s;
    std::vector<int> nums = {5, 7, 7, 8, 8, 10};
    print_vector(s.searchRange(nums, 8));
    print_vector(s.searchRange(nums, 6));
    return 0;
}


