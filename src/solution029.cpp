/**
 * 29. Divide Two Integers
 * Source: https://leetcode-cn.com/problems/divide-two-integers/
 */

#include <iostream>
#include <cmath>
#include <climits>

class solution029 {
public:

    // overtime
    static int divide(int dividend, int divisor) {
        bool negative = dividend < 0 ^divisor < 0;
        bool min1 = false, min2 = false;
        if (dividend == INT32_MIN) {
            min1 = true;
            dividend = INT32_MAX;
        } else if (dividend < 0) {
            dividend = std::abs(dividend);
        }
        if (divisor == INT32_MIN) {
            min2 = true;
            divisor = INT32_MAX;
        } else if (divisor < 0) {
            divisor = std::abs(divisor);
        }

        if (min2)
            return min1 ? 1 : 0;
        else {
            int res = 0;
            if (min1) {
                res = 1;
                dividend = dividend - divisor + 1;
            }
            while (dividend >= divisor) {
                res++;
                dividend = dividend - divisor;
            }
            if (negative)
                return res < 0 ? res : -res;
            else
                return res < 0 ? INT32_MAX : res;
        }
    }

    // 0ms, 100.00%; 5.9MB, 9.97%
    static int divide_v2(int dividend, int divisor) {
        bool negative = dividend < 0 ^divisor < 0;
        bool min1 = false, min2 = false;
        if (dividend == INT32_MIN) {
            min1 = true;
            dividend = INT32_MAX;
        } else if (dividend < 0) {
            dividend = std::abs(dividend);
        }
        if (divisor == INT32_MIN) {
            min2 = true;
            divisor = INT32_MAX;
        } else if (divisor < 0) {
            divisor = std::abs(divisor);
        }

        // 考虑特殊情况
        if (min2)  // divisor==-2^31
            return min1 ? 1 : 0;
        if (min1 && divisor == 1)  // dividend==-2^31 && dividend==1，可能会溢出
            return negative ? INT32_MIN : INT32_MAX;

        int bits[32] = {0};
        bits[0] = divisor;
        for (int i = 1; i < 32; i++) {
            int temp = bits[i - 1] << 1;
            if (temp < 0)
                break;
            bits[i] = temp;
        }

        int res = 0;
        if (min1) {
            res = 1;
            dividend = dividend - divisor + 1;
        }
        for (int i = 31; i >= 0; i--) {
            if (bits[i] == 0)
                continue;
            if (bits[i] <= dividend) {
                dividend -= bits[i];
                res += (1 << i);
            }
        }
        return negative ? -res : res;
    }
};

int main() {
    for (int i = -20; i < 20; i = i + 3) {
        for (int j = 2; j < 6; j++) {
            std::cout << (solution029::divide_v2(i, j) == i / j) << " ";
        }
    }
    std::cout << std::endl;
    std::cout << solution029::divide_v2(-2147483648, -1) << std::endl;
    std::cout << solution029::divide_v2(-2147483648, 1) << std::endl;
}
