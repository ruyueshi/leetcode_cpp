/**
 * JZ69. 跳台阶
 * Source: https://www.nowcoder.com/practice/8c82a5b80378478f9484d87d1c5f12a4?tpId=13&tqId=23261&ru=/exam/oj/ta&qru=/ta/coding-interviews/question-ranking&sourceUrl=%2Fexam%2Foj%2Fta%3Fpage%3D1%26tpId%3D13%26type%3D13
 */

#include <iostream>

class Solution {
public:
    int jumpFloor(int number) {
        if (number == 1) {
            return 1;
        } else if (number == 2) {
            return 2;
        }
        int dp_1 = 2, dp_2 = 1, res = 0;
        for (int i = 3; i <= number; i++) {
            res = dp_1 + dp_2;
            dp_2 = dp_1;
            dp_1 = res;
        }
        return res;
    }
};

int main() {
    Solution s;
    std::cout << s.jumpFloor(7) << std::endl;
    return 0;
}