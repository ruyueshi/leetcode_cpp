/**
 * JZ70. 矩形覆盖
 * Source: https://www.nowcoder.com/practice/72a5a919508a4251859fb2cfb987a0e6?tpId=13&tqId=23283&ru=/exam/oj/ta&qru=/ta/coding-interviews/question-ranking&sourceUrl=%2Fexam%2Foj%2Fta%3Fpage%3D1%26tpId%3D13%26type%3D13
 */

#include <iostream>

class SolutionV1 {
public:
    int rectCover(int number) {
        if (number == 0 || number == 1) {
            return number;
        }
        int dp[number + 1];
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= number; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[number];
    }
};

class SolutionV2 {
public:
    int rectCover(int number) {
        if (number == 0 || number == 1) {
            return number;
        }
        int dp_i = 2, dp_i_1 = 1, temp;
        for (int i = 3; i <= number; i++) {
            temp = dp_i;
            dp_i = dp_i + dp_i_1;
            dp_i_1 = temp;
        }
        return dp_i;
    }
};

int main() {
    SolutionV2 s;
    std::cout << s.rectCover(4) << std::endl;
    return 0;
}