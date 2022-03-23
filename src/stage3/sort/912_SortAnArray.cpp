/**
 * 912. Sort an Array
 * Source: https://leetcode-cn.com/problems/sort-an-array/
 */

#include <vector>

#include "src/utils/print.h"

// 归并排序
class Solution {
public:
    std::vector<int> sortArray(std::vector<int> &&nums) {
        temp.resize(nums.size());
        merge_sort(nums, 0, nums.size() - 1);
        return nums;
    }

private:
    std::vector<int> temp;

    void merge_sort(std::vector<int> &nums, int low, int high) {
        if (low >= high)
            return;
        int mid = low + (high - low) / 2;
        merge_sort(nums, low, mid);
        merge_sort(nums, mid + 1, high);
        merge(nums, low, mid, high);
    }

    void merge(std::vector<int> &nums, int low, int mid, int high) {
        for (int i = low; i <= high; i++) {
            temp[i] = nums[i];
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
    Solution s;
    auto res = s.sortArray({5, 2, 3, 1});
    print_vector(res);
    res = s.sortArray({5, 1, 1, 2, 0, 0});
    print_vector(res);
    return 0;
}
