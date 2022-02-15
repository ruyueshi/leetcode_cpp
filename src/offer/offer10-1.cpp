/**
 * offer 10-1. 裴波那契数列
 * Source: https://leetcode-cn.com/problems/fei-bo-na-qi-shu-lie-lcof/
 */

#include <iostream>

// 递归
// 费时，N稍微大点就算不出来
class SolutionV1 {
public:
    int fib(int n) {
        if (n <= 1)
            return n;
        else {
            return (fib(n - 1) % mod + fib(n - 2) % mod) % mod;
        }
    }

private:
    int mod = 1000000007;
};

// 动态规划
class SolutionV2 {
public:
    int fib(int n) {
        if (n <= 1)
            return n;
        int *d = new int[n + 1];
        d[0] = 0, d[1] = 1;
        for (int i = 2; i <= n; i++)
            d[i] = (d[i - 1] + d[i - 2]) % 1000000007;
        return d[n];
    }
};

// 动态规划
// 在V2的基础上改进：减伤存储空间
class SolutionV3 {
public:
    int fib(int n) {
        if (n <= 1)
            return n;
        int a = 0, b = 1, sum;
        for (int i = 2; i <= n; i++) {
            sum = (a + b) % 1000000007;
            a = b;
            b = sum;
        }
        return sum;
    }
};

int main() {
    SolutionV3 s;
    std::cout << s.fib(0) << std::endl;
    std::cout << s.fib(1) << std::endl;
    std::cout << s.fib(4) << std::endl;
    std::cout << s.fib(5) << std::endl;
    std::cout << s.fib(20) << std::endl;
    std::cout << s.fib(40) << std::endl;
    std::cout << s.fib(100) << std::endl;
    std::cout << s.fib(1000) << std::endl;
    return 0;
}
