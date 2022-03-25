/**
 * 315. Count of Smaller Numbers After Self
 * Source: https://leetcode-cn.com/problems/count-of-smaller-numbers-after-self/
 */

#include <algorithm>
#include <random>
#include <vector>

#include "src/utils/print.h"

class Solution {
public:
    std::vector<int> countSmaller(std::vector<int> &nums) {
        temp.resize(nums.size());
        std::vector<int> count(nums.size(), 0);
        std::vector<std::pair<int, int>> new_nums(nums.size());  // {value, index}
        for (int i = 0; i < nums.size(); i++)
            new_nums[i] = {nums[i], i};
        merge_sort(new_nums, count, 0, nums.size() - 1);
        return count;
    }

private:
    std::vector<std::pair<int, int>> temp;

    void merge_sort(std::vector<std::pair<int, int>> &nums, std::vector<int> &count, int low, int high) {
        if (low >= high)
            return;
        int mid = low + (high - low) / 2;
        merge_sort(nums, count, low, mid);
        merge_sort(nums, count, mid + 1, high);
        merge(nums, count, low, mid, high);
    }

    void merge(std::vector<std::pair<int, int>> &nums, std::vector<int> &count, int low, int mid, int high) {
        for (int i = low; i <= high; i++) {
            temp[i] = nums[i];
        }

        int i = low, j = mid + 1;
        for (int p = low; p <= high; p++) {
            if (i == mid + 1) {
                nums[p] = temp[j++];
            } else if (j == high + 1) {
                nums[p] = temp[i++];
                count[nums[p].second] += (j - mid - 1);
            } else if (temp[i].first <= temp[j].first) {
                nums[p] = temp[i++];
                count[nums[p].second] += (j - mid - 1);
            } else {
                nums[p] = temp[j++];
            }
        }
    }
};

int main() {
    Solution s;
    std::vector<int> nums = {5, 2, 6, 1};
    print_vector(s.countSmaller(nums));
    nums = {-1};
    print_vector(s.countSmaller(nums));
    nums = {-1, -1};
    print_vector(s.countSmaller(nums));
    return 0;
}
