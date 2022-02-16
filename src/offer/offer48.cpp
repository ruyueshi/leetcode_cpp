/**
 * offer 48. 最长不含重复字符的子字符串
 * Source: https://leetcode-cn.com/problems/zui-chang-bu-han-zhong-fu-zi-fu-de-zi-zi-fu-chuan-lcof/
 */

#include <iostream>
#include <map>
#include <string>
#include <vector>

class Solution {
public:
    int lengthOfLongestSubstringV1(std::string s) {
        if (s.length() < 1)
            return 0;
        std::vector<size_t> F(s.length());
        std::map<char, int> pos;
        F[0] = 1, pos[s[0]] = 0;
        int max_len = 1;
        for (size_t i = 1; i < s.length(); i++) {
            auto begin = pos.find(s[i]);
            if (begin == pos.end()) {
                F[i] = F[i - 1] + 1;
            } else {
                F[i] = std::min(i - begin->second, F[i - 1] + 1);
            }
            pos[s[i]] = i;
            if (F[i] > max_len)
                max_len = F[i];
        }
        return max_len;
    }

    // 压缩空间
    int lengthOfLongestSubstringV2(std::string s) {
        if (s.length() < 1)
            return 0;
        std::map<char, int> pos = {{s[0], 0}};
        int cur = 1, max_len = 1;
        for (int i = 1; i < s.length(); i++) {
            auto begin = pos.find(s[i]);
            int index = begin == pos.end() ? -1 : begin->second;
            if (i - index >= cur + 1) {
                cur = cur + 1;
            } else {
                cur = i - index;
            }
            pos[s[i]] = i;
            if (cur > max_len)
                max_len = cur;
        }
        return max_len;
    }
};

int main() {
    Solution s;
    std::cout << s.lengthOfLongestSubstringV2("abcabcbb") << std::endl;
    std::cout << s.lengthOfLongestSubstringV2("bbbbb") << std::endl;
    std::cout << s.lengthOfLongestSubstringV2("pwwkew") << std::endl;
    std::cout << s.lengthOfLongestSubstringV2("abba") << std::endl;
    return 0;
}
