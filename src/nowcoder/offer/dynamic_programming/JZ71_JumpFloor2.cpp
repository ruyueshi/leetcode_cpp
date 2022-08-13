/**
 * JZ71 跳台阶问题
 * Source: https://www.nowcoder.com/practice/22243d016f6b47f2a6928b4313c85387?tpId=13&tqId=23262&ru=/exam/oj/ta&qru=/ta/coding-interviews/question-ranking&sourceUrl=%2Fexam%2Foj%2Fta%3Fpage%3D1%26tpId%3D13%26type%3D13
 */

#include <iostream>
#include <cmath>

class Solution {
public:
    int jumpFloorII(int number) {
        return static_cast<int>(std::pow(2, number-1));
    }
};

int main() {
    Solution s;
    std::cout << s.jumpFloorII(5) << std::endl;
    return 0;
}