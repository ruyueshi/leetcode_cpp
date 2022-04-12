/**
 * 354. Russian Doll Envelopes
 * Source: https://leetcode-cn.com/problems/russian-doll-envelopes/
 */

#include <algorithm>
#include <iostream>
#include <vector>

// V1:超时
// 先对宽度进行升序排序，再对高度进行升序排序，再应用最长递增子序列的动态规划算法即可解决。
// 但是，这样会超时。V2比较巧妙
class SolutionV1 {
public:
    int maxEnvelopes(std::vector<std::vector<int>> &envelopes) {
        std::sort(envelopes.begin(), envelopes.end(), [](std::vector<int> a, std::vector<int> b) {
            return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
        });

        int n = envelopes.size();
        std::vector<int> dp(n, 1);
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1])
                    dp[i] = std::max(dp[i], dp[j] + 1);
            }
            res = std::max(res, dp[i]);
        }

        return res;
    }
};

// V2：先对宽度进行升序排序，再对高度进行降序排序（注意，此处和V1的差别）
// 这样操作，可保证在宽度升序的前提下，求高度的最长递增子序列即可。
// 需使用二分查找降低时间复杂度
class SolutionV2 {
public:
    int maxEnvelopes(std::vector<std::vector<int>> &envelopes) {
        std::sort(envelopes.begin(), envelopes.end(), [](std::vector<int> a, std::vector<int> b) {  // 注意，此处一定要传引用，频繁构造对象会导致超时
            // return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];  // 需要简化，不然也会超时
            return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
        });

        // O(N^2) 超时
        // int n = envelopes.size();
        // std::vector<int> dp(n, 1);
        // int res = 0;
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < i; j++) {
        //         if (envelopes[i][1] > envelopes[j][1])
        //             dp[i] = std::max(dp[i], dp[j] + 1);
        //     }
        //     res = std::max(res, dp[i]);
        // }

        // 二分查找
        int n = envelopes.size();
        std::vector<int> top;
        int heap_num = 0;
        for (int i = 0; i < n; i++) {
            int candidate = envelopes[i][1];
            int left = 0, right = heap_num;
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (top[mid] == candidate) {
                    left = mid;
                    break;
                } else if (top[mid] < candidate)
                    left = mid + 1;
                else
                    right = mid;
            }
            if (left == heap_num) {
                heap_num++;
                top.push_back(candidate);
            } else
                top[left] = candidate;
        }

        return heap_num;
    }
};

int main() {
    SolutionV2 s;
    std::vector<std::vector<int>> envelopes = {{5, 4},
                                               {6, 4},
                                               {6, 7},
                                               {2, 3}};
    std::cout << s.maxEnvelopes(envelopes) << std::endl;
    envelopes = {{1, 1},
                 {1, 1},
                 {1, 1}};
    std::cout << s.maxEnvelopes(envelopes) << std::endl;
    envelopes = {{15, 8},
                 {2,  20},
                 {2,  14},
                 {4,  17},
                 {8,  19},
                 {8,  9},
                 {5,  7},
                 {11, 19},
                 {8,  11},
                 {13, 11},
                 {2,  13},
                 {11, 19},
                 {8,  11},
                 {13, 11},
                 {2,  13},
                 {11, 19},
                 {16, 1},
                 {18, 13},
                 {14, 17},
                 {18, 19}};
    std::cout << s.maxEnvelopes(envelopes) << std::endl;
    return 0;
}
