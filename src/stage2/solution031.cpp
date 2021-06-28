/**
 * 31. Next Permutation
 * Source: https://leetcode-cn.com/problems/next-permutation/
 */

#include <iostream>
#include <vector>
#include <algorithm>

class solution031 {
public:
    void nextPermutation(std::vector<int> &nums) {
        if (nums.size() <= 1)
            return;
        int i = nums.size() - 2, j = nums.size() - 1, k = j;

        while ((i >= 0 && nums[i] >= nums[j])) {
            i--, j--;
        }

        if (i >= 0) {
            while (k >= j && nums[k] <= nums[i])
                k--;
            std::swap(nums[i], nums[k]);
        }

        std::reverse(nums.begin() + j, nums.end());
    }

private:
    void permutation(std::vector<int> &nums, int start, int end) {
        if (start == end) {
            std::for_each(nums.begin(), nums.end(), [](int e) { std::cout << e << " "; });
            std::cout << std::endl;
        } else {
            for (int i = start; i <= end; i++) {
                std::swap(nums[start], nums[i]);
                permutation(nums, start + 1, end);
                std::swap(nums[start], nums[i]);
            }
        }
    }
};

int main() {
    solution031 s;
    std::vector<int> a = {9, 7, 1};
    std::cout << "====== gt:\n";
    while (std::next_permutation(a.begin(), a.end())) {
        std::for_each(a.begin(), a.end(), [](int e) { std::cout << e << " "; });
        std::cout << std::endl;
    }
    std::vector<int> b = {4, 2, 0, 2, 3, 2, 0};
    std::cout << "====== pred:\n";
    s.nextPermutation(b);
    std::for_each(b.begin(), b.end(), [](int e) { std::cout << e << " "; });
    std::cout << std::endl;
    return 0;
}
