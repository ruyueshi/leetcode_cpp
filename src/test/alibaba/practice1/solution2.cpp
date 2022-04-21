/*
链接：https://www.nowcoder.com/question/next?pid=30440638&qid=1664953&tid=55624658
来源：牛客网
小强发现当已知以及时,能很轻易的算出的值.但小强想请你在已知 和的情况下,计算出的值.因为这个结果可能很大,所以所有的运算都在模1e9+7下进行.

输入描述:
第一行输入一个正整数.表示有组数据
接下来行,每行输入三个整数,和.




输出描述:
输出行,每一行表示每组数据的结果.

输入例子1:
3
4 4 3
2 3 4
5 2 6

输出例子1:
16
999999993
9009
 */

#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>

long long mod = 1e9 + 7;

long long solve(int A, int B, int n) {
    if (n == 1)
        return A;
    std::vector<long long> dp(n);
    dp[0] = A;
    dp[1] = ((long long) std::pow(A, 2) % mod - 2 * (long long) B % mod) % mod;
    for (int i = 2; i < n; i++) {
        dp[i] = ((A * dp[i - 1]) % mod - (B * dp[i - 2]) % mod) % mod;
    }
    return (dp[n - 1] + mod) % mod;
}

int main() {
    int T, A, B, n;
    std::cin >> T;
    for (int i = 0; i < T; i++) {
        std::cin >> A >> B >> n;
        std::cout << solve(A, B, n) << std::endl;
    }
    return 0;
}
