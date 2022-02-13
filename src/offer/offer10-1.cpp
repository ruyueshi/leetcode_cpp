/**
 * offer 10-1. 裴波那契数列
 * Source: https://leetcode-cn.com/problems/fei-bo-na-qi-shu-lie-lcof/
 */

#include <iostream>

class Solution {
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

int main() {
    Solution s;
    std::cout << s.fib(0) << std::endl;
    std::cout << s.fib(1) << std::endl;
    std::cout << s.fib(4) << std::endl;
    std::cout << s.fib(5) << std::endl;
    std::cout << s.fib(20) << std::endl;
    std::cout << s.fib(40) << std::endl;
    std::cout << s.fib(100) << std::endl;
    return 0;
}
