/**
 * offer 58-1. 翻转单词顺序
 * Source: https://leetcode-cn.com/problems/fan-zhuan-dan-ci-shun-xu-lcof/
 */

#include <iostream>
#include <stack>
#include <string>

class Solution {
public:
    // 时间复杂度O(N)，空间复杂度O(N)
    std::string reverseWordsV1(std::string s) {
        std::stack<std::string> st;
        size_t i = 0, j = 0;
        while (i < s.size() && j < s.size()) {
            i = j;
            while (i < s.size() && s[i] == ' ')
                i++;
            j = i;
            while (j < s.size() && s[j] != ' ')
                j++;
            if (i < s.size() && j - 1< s.size())
                st.push(s.substr(i, j - i));
        }
        if (st.empty())
            return "";
        std::string res = st.top();
        st.pop();
        while (!st.empty()) {
            res += " " + st.top();
            st.pop();
        }
        return res;
    }

    // 倒序遍历字符串，可以不依赖栈，优化空间存储
    std::string reverseWordsV2(std::string s) {
        std::string res;
        int i = s.size() - 1, j = i;
        while (i >= 0 && j >= 0) {
            i = j;
            while (i >= 0  && s[i] == ' ')
                i--;
            j = i;
            while (j >= 0 && s[j] != ' ')
                j--;
            if (i >= 0 && j + 1 >= 0)
                res += s.substr(j + 1, i - j) + " ";
        }
        if (!res.empty())
            res.pop_back();
        return res;
    }
};

int main() {
    Solution s;
    std::cout << s.reverseWordsV2("the sky is blue") << std::endl;
    std::cout << s.reverseWordsV2("  hello world!  ") << std::endl;
    return 0;
}