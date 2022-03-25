/**
 * 493. Reverse Pairs
 * Source: https://leetcode-cn.com/problems/reverse-pairs/
 */

#include <iostream>
#include <vector>

class Solution {
public:
    int reversePairs(std::vector<int> &nums) {
        temp.resize(nums.size());
        merge_sort(nums, 0, nums.size() - 1);
        return count;
    }

private:
    std::vector<int> temp;
    int count = 0;

    void merge_sort(std::vector<int> &nums, int low, int high) {
        if (low >= high)
            return;
        int mid = low + (high - low) / 2;
        merge_sort(nums, low, mid);
        merge_sort(nums, mid + 1, high);
        merge(nums, low, mid, high);
    }

    void merge(std::vector<int> &nums, int low, int mid, int high) {
        for (int i = low; i <= high; i++)
            temp[i] = nums[i];

        int end = mid + 1;
        for (int i = low; i <= mid; i++) {
            while (end <= high && (long long) nums[i] > (long long) nums[end] * 2)
                end++;
            count += end - (mid + 1);
        }

        int i = low, j = mid + 1;
        for (int p = low; p <= high; p++) {
            if (i == mid + 1) {
                nums[p] = temp[j++];
            } else if (j == high + 1) {
                nums[p] = temp[i++];
            } else if (temp[i] <= temp[j]) {
                nums[p] = temp[i++];
            } else {
                nums[p] = temp[j++];
            }
        }
    }
};

int main() {
    std::vector<int> nums = {1, 3, 2, 3, 1};
    std::cout << Solution().reversePairs(nums) << std::endl;
    nums = {-1};
    std::cout << Solution().reversePairs(nums) << std::endl;
    nums = {2, 4, 3, 5, 1};
    std::cout << Solution().reversePairs(nums) << std::endl;
    return 0;
}
