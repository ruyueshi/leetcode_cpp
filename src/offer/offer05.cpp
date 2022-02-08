/**
 * offer 05. 替换空格
 * Source: https://leetcode-cn.com/problems/ti-huan-kong-ge-lcof/
 */

#include <iostream>
#include <string>

class Solution {
public:
    std::string replaceSpace(std::string s) {
        if (s.empty())
            return "";
        int i = 0;
        while (i < s.length()) {
            if (s[i] == ' ') {
                s.erase(s.begin() + i);
                s.insert(i, "%20");
                i += 3;
            } else {
                i += 1;
            }
        }
        return s;
    }
};

int main() {
    Solution s;
    std::string str = "     ";
    std::cout << s.replaceSpace(str) << std::endl;
    return 0;
}
