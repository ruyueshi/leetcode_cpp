/**
 * offer 58-2. 左旋转字符串
 * Source: https://leetcode-cn.com/problems/zuo-xuan-zhuan-zi-fu-chuan-lcof/
 */

#include <iostream>
#include <string>

class Solution {
public:
    std::string reverseLeftWords(std::string s, int n) {
        return s.substr(n) + s.substr(0, n);
    }
};

int main() {
    Solution s;
    std::string str = "lrloseumgh";
    std::cout << s.reverseLeftWords(str, 6) << std::endl;
    return 0;
}