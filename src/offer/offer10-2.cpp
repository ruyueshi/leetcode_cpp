/**
 * offer 10-2. 青蛙跳台阶问题
 * Source: https://leetcode-cn.com/problems/qing-wa-tiao-tai-jie-wen-ti-lcof/
 */

#include <iostream>

class SolutionV1 {
public:
    int numWays(int n) {
        if (n <= 1)
            return 1;
        int *d = new int[n + 1];
        d[0] = d[1] = 1;
        for (int i = 2; i <= n; i++)
            d[i] = (d[i-1] +d[i-2]) % 1000000007;
        return d[n];
    }
};

class SolutionV2 {
public:
    int numWays(int n) {
        if (n <= 1)
            return 1;
        int a = 1, b = 1, sum;
        for (int i = 2; i <= n; i++) {
            sum = (a + b) % 1000000007;
            a = b;
            b = sum;
        }
        return sum;
    }

    int numWaysV2(int n) {
        int a = 1, b = 1, sum;
        for (int i = 0; i < n; i++) {
            sum = (a + b) % 1000000007;
            a = b;
            b = sum;
        }
        return a;
    }
};

int main() {
    SolutionV2 s;
    std::cout << s.numWays(0) << std::endl;
    std::cout << s.numWays(1) << std::endl;
    std::cout << s.numWays(2) << std::endl;
    std::cout << s.numWays(4) << std::endl;
    std::cout << s.numWays(5) << std::endl;
    std::cout << s.numWays(20) << std::endl;
    std::cout << s.numWays(40) << std::endl;
    std::cout << s.numWays(100) << std::endl;
    std::cout << s.numWays(1000) << std::endl;
    return 0;
}