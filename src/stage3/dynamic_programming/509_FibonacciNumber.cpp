/**
 * 509. Fibonacci Number
 * Source: https://leetcode-cn.com/problems/fibonacci-number/
 */

#include <iostream>

class Solution {
public:
    int fib(int n) {
        if (n == 0 || n == 1)
            return n;
        int dp1 = 0, dp2 = 1, res;
        for (int i = 2; i <= n; i++) {
            res = dp1 + dp2;
            dp1 = dp2;
            dp2 = res;
        }
        return res;
    }
};

int main() {
    Solution s;
    std::cout << s.fib(1) << std::endl;
    std::cout << s.fib(2) << std::endl;
    std::cout << s.fib(20) << std::endl;
    return 0;
}
