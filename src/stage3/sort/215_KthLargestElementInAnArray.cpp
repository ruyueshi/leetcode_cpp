/**
 * 215. Kth Largest Element in an Array
 * Source: https://leetcode-cn.com/problems/kth-largest-element-in-an-array/
 */

#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

#include "src/utils/print.h"

class Solution {
public:
    int findKthLargest(std::vector<int> &nums, int k) {
        std::shuffle(nums.begin(), nums.end(), std::default_random_engine(0));
        int n = nums.size();
        quick_sort(nums, 0, n - 1);
        return nums[n - k];
    }

private:
    void quick_sort(std::vector<int> &nums, int low, int high) {
        if (low >= high)
            return;
        int p = partition(nums, low, high);
        quick_sort(nums, low, p - 1);
        quick_sort(nums, p + 1, high);
    }

    int partition(std::vector<int> &nums, int low, int high) {
        int key = nums[low];
        int i = low, j = high;
        while (i < j) {
            while (i < j && nums[j] >= key)
                j--;
            if (i < j)
                nums[i++] = nums[j];  // 之所以需要++，是因为nums[i]=nums[j]后，nums[i]一定小于key（因为nums[j]小于key）
            while (i < j && nums[i] <= key)
                i++;
            if (i < j)
                nums[j--] = nums[i];
        }
        nums[i] = key;
        return i;
    }
};

int main() {
    Solution s;
    std::vector<int> nums = {3, 2, 1, 5, 6, 4};
    std::cout << s.findKthLargest(nums, 2) << std::endl;
    print_vector(nums);
    nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    std::cout << s.findKthLargest(nums, 4) << std::endl;
    print_vector(nums);
    return 0;
}
