/**
 * offer 46. 把数字翻译成字符串
 * Source: https://leetcode-cn.com/problems/ba-shu-zi-fan-yi-cheng-zi-fu-chuan-lcof/
 */

#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    int translateNumV1(int num) {
        if (num < 10)
            return 1;
        std::string s = std::to_string(num);
        std::vector<int> F(s.length());
        F[0] = 1, F[1] = can_trans(s.substr(0, 2)) ? 2 : 1;
        for (size_t i = 2; i < s.length(); i++) {
            if (can_trans(s.substr(i - 1, 2)))
                F[i] = F[i - 1] + F[i - 2];
            else
                F[i] = F[i - 1];
        }
        return F[s.length() - 1];
    }

    // 压缩空间
    int translateNumV2(int num) {
        if (num < 10)
            return 1;
        std::string s = std::to_string(num);
        int pre1 = 1, pre2 = can_trans(s.substr(0, 2)) ? 2 : 1, cur = pre2;
        for (size_t i = 2; i < s.length(); i++) {
            if (can_trans(s.substr(i - 1, 2)))
                cur = pre1 + pre2;
            else
                cur = pre2;
            pre1 = pre2;
            pre2 = cur;
        }
        return cur;
    }

    bool can_trans(std::string substr) {
        if (substr >= "10" && substr <= "25")
            return true;
        else
            return false;
    }
};

int main() {
    Solution s;
    std::cout << s.translateNumV2(12258) << std::endl;
    return 0;
}
