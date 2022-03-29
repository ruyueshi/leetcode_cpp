/**
 * 303. Range Sum Query - Immutable
 * Source: https://leetcode-cn.com/problems/range-sum-query-immutable/
 */

#include <iostream>
#include <vector>

class NumArray {
public:
    NumArray(std::vector<int> &nums) {
        pre_sum.resize(nums.size() + 1);
        int sum = 0;
        pre_sum[0] = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            pre_sum[i + 1] = sum;
        }
    }

    int sumRange(int left, int right) {
        return pre_sum[right + 1] - pre_sum[left];
    }

private:
    std::vector<int> pre_sum;
};

int main() {
    std::vector<int> v = {-2, 0, 3, -5, 2, -1};
    NumArray n(v);
    std::cout << n.sumRange(0, 2) << std::endl;
    std::cout << n.sumRange(2, 5) << std::endl;
    std::cout << n.sumRange(0, 5) << std::endl;
    return 0;
}
