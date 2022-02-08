/**
 * offer 53-2. 0～n-1中缺失的数字
 * Source: https://leetcode-cn.com/problems/que-shi-de-shu-zi-lcof/
 */

#include <iostream>
#include <vector>

class Solution {
public:
    int missingNumber(std::vector<int>& nums) {
        if (nums.size() == 0)
            return -1;
        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] == mid)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low;
    }

private:
    int binary_search(const std::vector<int> &nums, int low, int high) {
        if (low > high) {
            return -1;
        } else {
            int mid = (high + low) / 2;
            if (mid != nums[mid])
                return mid;
            else {
                int temp = this->binary_search(nums, low, mid - 1);
                if (temp > 0)
                    return temp;
                else
                    return this->binary_search(nums, mid + 1, high);
            }
        }
    }
};

int main() {
    Solution s;
    std::vector<int> a = {0,1,2,3,4,5,6,7,9};
    std::cout << s.missingNumber(a) << std::endl;
    return 0;
}
