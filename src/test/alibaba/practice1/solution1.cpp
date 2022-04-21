/*
链接：https://www.nowcoder.com/question/next?pid=30440638&qid=1664962&tid=55284776
来源：牛客网
小强现在有个物品,每个物品有两种属性和.他想要从中挑出尽可能多的物品满足以下条件:对于任意两个物品和,满足或者.问最多能挑出多少物品.

进阶：时间复杂度，空间复杂度

输入描述:
第一行输入一个正整数.表示有组数据.
对于每组数据,第一行输入一个正整数.表示物品个数.
接下来两行,每行有个整数.
第一行表示个节点的属性.
第二行表示个节点的属性.




输出描述:
输出行,每一行对应每组数据的输出.

输入例子1:
2
3
1 3 2
0 2 3
4
1 5 4 2
10 32 19 21

输出例子1:
2
3
 */

#include <algorithm>
#include <iostream>
#include <vector>

// V1：动态规划，O(n^2)
int get_most_products_v1(std::vector<std::vector<int>> &nums) {
    std::sort(nums.begin(), nums.end(), [](const std::vector<int> &a, const std::vector<int> &b) {
        return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
    });

    int n = nums.size(), res = 0;
    std::vector<int> dp(n, 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i][1] > nums[j][1])
                dp[i] = std::max(dp[i], dp[j] + 1);
        }
        res = std::max(res, dp[i]);
    }
    return res;
}

// V2：二分查找
int get_most_products_v2(std::vector<std::vector<int>> &nums) {
    std::sort(nums.begin(), nums.end(), [](const std::vector<int> &a, const std::vector<int> &b) {
        return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
    });

    int n = nums.size(), res = 0;
    std::vector<int> top;
    for (int i = 0; i < n; i++) {
        int candidate = nums[i][1];
        int left = 0, right = top.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (candidate == top[mid]) {
                left = mid;
                break;
            } else if (candidate < top[mid]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        if (left >= top.size()) {
            top.push_back(candidate);
        } else {
            top[left] = candidate;
        }
    }
    return top.size();
}

int main() {
    // std::ios::sync_with_stdio(false);
    int T, n;
    std::cin >> T;
    for (int i = 0; i < T; i++) {
        std::cin >> n;
        std::vector<std::vector<int>> nums(n, std::vector<int>(2));
        for (int j = 0; j < n; j++)
            std::cin >> nums[j][0];
        for (int j = 0; j < n; j++)
            std::cin >> nums[j][1];
        std::cout << get_most_products_v2(nums) << std::endl;
    }
    return 0;
}
