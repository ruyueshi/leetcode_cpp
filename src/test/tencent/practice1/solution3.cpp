/*
链接：https://www.nowcoder.com/question/next?pid=38431372&qid=2500134&tid=55738913
来源：牛客网
我们定义一个有效序列为：该序列两端的数一个为最小值，另一个为次小值。（即序列两端以外的数一定大于等于最左边的数且大于等于最右边的数）

现在给你一个序列 a ，想让你找到它的连续子序列中有多少个有效序列(比如 ，1 2 ，2 3，1 2 3 是序列 1 2 3 的连续子序列，但是 1 3 不是)

注：长度为 2 的子序列，一定为有效序列，长度为 1 的子序列，一定不是有效序列

输入描述:
第一行输入一个整数 n 代表这个序列的长度
接下来输入 n 个整数，a[i] 代表系列中第 i 个元素

对于 20% 的数据, 1 ≤ n ≤ 100
对于 70% 的数据, 1 ≤ n ≤ 3,000
对于 100% 的数据, 1 ≤ n ≤ 100,000

对于 100% 的数据, 1 ≤ a[i] ≤ 1,000,000,000

输出描述:
输出一个正整数表示有效序列的数量。

输入例子1:
4
1 3 1 2

输出例子1:
4

例子说明1:
一共有 4 组有效序列，分别为：
子序列[1,3] 因为长度为 2，一定为有效序列
子序列[1,3,1] 因为第2个数 “3” 大于第 1 个数和第 3 个数
子序列[3,1] 因为长度为 2，一定为有效序列
子序列[1,2] 因为长度为 2，一定为有效序列

输入例子2:
4
1 1 2 1

输出例子2:
5

例子说明2:
一共有6个长度不小于2的连续子序列，除了[1,1,2]以外，其他5个都是有效子序列

输入例子3:
7
1 4 2 5 7 1 3

输出例子3:
10

例子说明3:
一共有10组，分别为：
[1,4], [1,4,2], [1,4,2,5,7,1], [4,2], [2,5], [2,5,7,1], [5,7], [5,7,1], [7,1], [1,3]
 */

#include <iostream>
#include <vector>

// 超时
int solve_v1(std::vector<int> &arr, int n) {
    int res = n - 1;  // 长度为2的连续子序列的数量为n-1
    for (int i = 0; i <= n - 3; i++) {
        for (int j = i + 2; j <= n - 1; j++) {
            int k = i + 1;
            for (; k < j; k++) {
                if (arr[k] < arr[i] || arr[k] < arr[j])
                    break;
            }
            if (k == j)
                res++;
        }
    }
    return res;
}

// 超时
int solve_v2(std::vector<int> &arr, int n) {
    std::vector<std::vector<bool>> dp(n, std::vector<bool>(n));
    for (int i = 0; i <= n - 2; i++)
        dp[i][i + 1] = true;
    int res = n - 1;
    for (int i = n - 3; i >= 0; i--) {
        for (int j = i + 2; j <= n - 1; j++) {
            if (dp[i + 1][j]) {
                if (arr[i + 1] >= arr[i] && arr[i + 1] >= arr[j])
                    dp[i][j] = true;
            } else if (dp[i][j - 1]) {
                if (arr[j - 1] >= arr[i] && arr[j - 1] >= arr[j])
                    dp[i][j] = true;
            } else {
                dp[i][j] = true;
                for (int k = i + 1; k <= j - 1; k++) {
                    if (arr[k] < arr[i] || arr[k] < arr[j]) {
                        dp[i][j] = false;
                        break;
                    }
                }
            }
            if (dp[i][j])
                res++;
        }
    }
    return res;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++)
        std::cin >> arr[i];
    std::cout << solve_v2(arr, n) << std::endl;
    return 0;
}
