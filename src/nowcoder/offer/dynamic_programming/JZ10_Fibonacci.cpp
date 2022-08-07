/**
 * JZ10. 裴波那契数列
 * Source: https://www.nowcoder.com/practice/c6c7742f5ba7442aada113136ddea0c3?tpId=13&tqId=23255&ru=/exam/oj/ta&qru=/ta/coding-interviews/question-ranking&sourceUrl=%2Fexam%2Foj%2Fta%3Fpage%3D1%26tpId%3D13%26type%3D13
 */

#include <iostream>

class Solution {
public:
    int Fibonacci(int n) {
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
    std::cout << Solution().Fibonacci(4) << std::endl;
    return 0;
}