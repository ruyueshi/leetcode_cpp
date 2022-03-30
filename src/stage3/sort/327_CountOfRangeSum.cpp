/**
 * 327. Count of Range Sum
 * Source: https://leetcode-cn.com/problems/count-of-range-sum/
 */

#include <iostream>
#include <unordered_map>
#include <vector>

// 超时
class SolutionV1 {
public:
    int countRangeSum(std::vector<int> &nums, int lower, int upper) {
        std::unordered_map<long long, int> hashmap;  // // {前缀和，前缀和出现的次数};
        hashmap.insert({0, 1});
        int n = nums.size(), count = 0;
        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            long long pre_sum1 = sum - upper, pre_sum2 = sum - lower;
            for (long long j = pre_sum1; j <= pre_sum2; ++j) {
                if (hashmap[j] > 0) {
                    count += hashmap[j];
                }
            }
            hashmap[sum]++;
        }
        return count;
    }
};

// 归并排序
class SolutionV2 {
public:
    int countRangeSum(std::vector<int> &nums, int _lower, int _upper) {
        count = 0, lower = _lower, upper = _upper;
        int n = nums.size();
        std::vector<long long> pre_sum(n + 1);
        temp.resize(n + 1);
        pre_sum[0] = 0;
        for (int i = 0; i < n; ++i)
            pre_sum[i + 1] = pre_sum[i] + nums[i];
        merge_sort(pre_sum, 0, n);
        return count;
    }

private:
    int count, lower, upper;
    std::vector<long long> temp;

    void merge_sort(std::vector<long long> &pre_sum, int left, int right) {
        if (left >= right)
            return;
        int mid = left + (right - left) / 2;
        merge_sort(pre_sum, left, mid);
        merge_sort(pre_sum, mid + 1, right);
        merge(pre_sum, left, mid, right);
    }

    void merge(std::vector<long long> &pre_sum, int left, int mid, int right) {
        for (int i = left; i <= right; ++i)
            temp[i] = pre_sum[i];

        // 区间左开右闭
        int start = mid + 1, end = mid + 1;
        for (int i = left; i <= mid; ++i) {
            while (start <= right && pre_sum[start] - pre_sum[i] < lower)
                start++;
            while (end <= right && pre_sum[end] - pre_sum[i] <= upper)
                end++;
            count += end - start;
        }

        // 合并
        int i = left, j = mid + 1;
        for (int p = left; p <= right; ++p) {
            if (i == mid + 1)
                pre_sum[p] = temp[j++];
            else if (j == right + 1)
                pre_sum[p] = temp[i++];
            else if (temp[i] <= temp[j])
                pre_sum[p] = temp[i++];
            else
                pre_sum[p] = temp[j++];
        }
    }
};

int main() {
    SolutionV2 s;
    std::vector<int> nums = {-2, 5, -1};
    std::cout << s.countRangeSum(nums, -2, 2) << std::endl;
    return 0;
}
