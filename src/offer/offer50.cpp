/**
 * offer 50. 第一个只出现一次的字符
 * Source: https://leetcode-cn.com/problems/di-yi-ge-zhi-chu-xian-yi-ci-de-zi-fu-lcof/
 */

#include <iostream>
#include <queue>
#include <string>

class Solution {
public:
    char firstUniqChar(std::string s) {
        int flag[26] = {0};
        for (auto &i: s) {
            flag[i - 'a']++;
        }
        for (auto &i: s) {
            if (flag[i - 'a'] == 1) {
                return i;
            }
        }
        return ' ';
    }
};

int main() {
    Solution s;
    std::cout << s.firstUniqChar("abaccdeff") << std::endl;
    std::cout << s.firstUniqChar("") << std::endl;
    return 0;
}
