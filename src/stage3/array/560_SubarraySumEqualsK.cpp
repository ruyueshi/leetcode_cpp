/**
 * 560. Subarray Sum Equals K
 * Source: https://leetcode-cn.com/problems/subarray-sum-equals-k/
 */

#include <iostream>
#include <vector>
#include <unordered_map>

// 超时
class SolutionV1 {
public:
    int subarraySum(std::vector<int> &nums, int k) {
        int n = nums.size();
        std::vector<int> pre_sum(n + 1);
        pre_sum[0] = 0;
        for (int i = 1; i <= n; i++)
            pre_sum[i] = pre_sum[i - 1] + nums[i - 1];
        int count = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                if (pre_sum[j + 1] - pre_sum[i] == k)
                    count++;
            }
        }
        return count;
    }
};

class SolutionV2 {
public:
    int subarraySum(std::vector<int> &nums, int k) {
        int n = nums.size();
        std::unordered_map<int, int> hashmap; // {前缀和，前缀和出现的次数};
        hashmap.insert({0, 1});
        int count = 0, sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            int pre_sum = sum - k;
            if (hashmap[pre_sum] > 0)
                count += hashmap[pre_sum];
            hashmap[sum]++;
        }
        return count;
    }
};

int main() {
    SolutionV2 s;
    std::vector<int> nums = {1, 2, 3};
    std::cout << s.subarraySum(nums, 3) << std::endl;
    return 0;
}
