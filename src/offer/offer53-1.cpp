/**
 * offer 53-1. 在排序数组中查找数字
 * Source: https://leetcode-cn.com/problems/zuo-xuan-zhuan-zi-fu-chuan-lcof/
 */

#include <iostream>
#include <vector>

class SolutionV1 {
public:
    int search(std::vector<int>& nums, int target) {
        if (nums.size() == 0)
            return 0;
        int pos = this->binary_search(nums, target, 0, nums.size() - 1);
        int count = 0;
        if (pos >= 0) {
            int i = pos;
            while (i < nums.size() && nums[i] == target) {
                count++;
                i += 1;
            }
            i = pos - 1;
            while (i >= 0 && nums[i] == target) {
                count++;
                i -= 1;
            }
        }
        return count;
    }

private:
    int binary_search(const std::vector<int> &nums, int target, int low, int high) {
        if (low > high) {
            return -1;
        } else {
            int mid = (high + low) / 2;
            if (target == nums[mid])
                return mid;
            else if (target < nums[mid])
                return this->binary_search(nums, target, low, mid - 1);
            else
                return this->binary_search(nums, target, mid + 1, high);
        }
    }
};

class SolutionV2 {
public:
    int search(std::vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (target < nums[mid]) {
                high = mid - 1;
            } else if (target > nums[mid]) {
                low = mid + 1;
            } else {
                if (nums[low] != target)
                    low ++;
                else if (nums[high] != target)
                    high --;
                else
                    break;
            }
        }
        return high - low + 1;
    }
};

int main() {
    SolutionV2 s;
    std::vector<int> a = {5,7,7,8,8,10};
    std::cout << s.search(a, 8) << std::endl;
    return 0;
}
