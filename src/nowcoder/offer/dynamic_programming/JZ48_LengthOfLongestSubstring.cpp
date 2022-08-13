/**
 * JZ48 最长不含重复字符的子字符串
 * Source: https://www.nowcoder.com/practice/48d2ff79b8564c40a50fa79f9d5fa9c7?tpId=13&tqId=2276769&ru=/exam/oj/ta&qru=/ta/coding-interviews/question-ranking&sourceUrl=%2Fexam%2Foj%2Fta%3Fpage%3D1%26tpId%3D13%26type%3D13
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param s string字符串
     * @return int整型
     */
    int lengthOfLongestSubstring(string s) {
        // write code here
        int n = s.size();
        std::unordered_map<char, int> index_table;
        int max_len = 0, current_start = 0;
        for (int i = 0; i < n; i++) {
            auto it = index_table.find(s[i]);
            if (it != index_table.end()) {
                current_start = std::max(current_start, it->second + 1);  // abcadcbb
            }
            index_table[s[i]] = i;
            max_len = std::max(max_len, i - current_start + 1);
        }
        return max_len;
    }
};

int main() {
    Solution s;
    std::cout << s.lengthOfLongestSubstring("abcabcbb") << std::endl;
    std::cout << s.lengthOfLongestSubstring("bbbbb") << std::endl;
    return 0;
}
