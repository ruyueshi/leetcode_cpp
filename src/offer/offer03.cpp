/**
 * offer 03. 数组中重复的数字
 * Source: https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/
 */

#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

class SolutionV1 {
public:
    int findRepeatNumber(std::vector<int>& nums) {
        std::set<int> s;
        for (auto &i : nums) {
            if (s.find(i) == s.end())
                s.insert(i);
            else
                return i;
        }
        return -1;
    }
};

class SolutionV2 {
public:
    int findRepeatNumber(std::vector<int>& nums) {
        std::vector<int> index(nums.size(), -1);
        for (auto &i : nums) {
            if (index[i] == -1)
                index[i] = 1;
            else
                return i;
        }
        return -1;
    }
};

class SolutionV3 {
public:
    int findRepeatNumber(std::vector<int>& nums) {
        int i = 0;
        while (i < nums.size()) {
            if (nums[i] == i) {
                i++;
                continue;
            }
            if (nums[i] == nums[nums[i]])
                return nums[i];
            std::swap(nums[i], nums[nums[i]]);
        }
        return -1;
    }
};

int main() {
    SolutionV3 s;
    std::vector<int> in = {3,4,2,0,0,1};
    std::cout << s.findRepeatNumber(in) << std::endl;
    return 0;
}
