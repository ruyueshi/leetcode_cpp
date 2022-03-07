/**
 * 704. Binary Search
 * Source: https://leetcode-cn.com/problems/binary-search/
 */

#include <iostream>
#include <vector>

class Solution {
public:
    int search(std::vector<int> &nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return -1;
    }
};

int main() {
    Solution s;
    std::vector<int> nums = {-1, 0, 3, 5, 9, 12};
    std::cout << s.search(nums, 9) << std::endl;
    std::cout << s.search(nums, 2) << std::endl;
    return 0;
}
