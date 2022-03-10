/**
 * 76. Minimum Window Substring
 * Source: https://leetcode-cn.com/problems/minimum-window-substring/
 */

#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;

// 笨办法，非常耗时
class SolutionV1 {
public:
    string minWindow(string s, string t) {
        std::unordered_map<char, int> char_table;  // 统计字符串t中各个字符的数量
        std::unordered_map<char, std::queue<int>> m;  // 统计每个字符在字符串中出现的位置
        for (const auto &c: t)
            char_table[c]++;
        int min_len = s.size() + 1, min_start = -1, current_start = -1;
        for (int i = 0; i < s.size(); i++) {
            if (char_table.find(s[i]) != char_table.end()) {
                m[s[i]].push(i);
                current_start = get_min(char_table, m);
                while (current_start > -1 && m[s[current_start]].size() > char_table[s[current_start]]) {
                    m[s[current_start]].pop();
                    current_start = get_min(char_table, m);
                }
                if (current_start > -1) {
                    int current_len = i - current_start + 1;
                    if (current_len < min_len) {
                        min_len = current_len;
                        min_start = current_start;
                    }
                }
            }
        }
        return min_len == s.size() + 1 ? "" : s.substr(min_start, min_len);
    }

private:
    int get_min(std::unordered_map<char, int> &char_table, std::unordered_map<char, std::queue<int>> &m) {
        if (char_table.size() != m.size())
            return -1;
        int temp_min_start = INT32_MAX;
        for (auto it = m.begin(); it != m.end(); ++it) {
            if (it->second.size() < char_table[it->first])
                return -1;
            if (it->second.front() < temp_min_start)  // m['A']的大小必须大于char_table['A']才可以进行后续pop出m最小值位置
                temp_min_start = it->second.front();
        }
        return temp_min_start;
    }
};

// 滑动窗口
class SolutionV2 {
public:
    string minWindow(string s, string t) {
        std::unordered_map<char, int> char_table;  // 统计字符串t中各个字符的数量
        std::unordered_map<char, int> window;  // 统计当前窗口中各个字符的数量
        for (const auto &c: t)
            char_table[c]++;
        int min_len = INT_MAX, min_start = 0, left = 0, right = 0;
        int valid = 0;
        while (right < s.size()) {
            char right_ch = s[right];
            right++;
            if (char_table.find(right_ch) != char_table.end()) {
                window[right_ch]++;
                if (char_table[right_ch] == window[right_ch])  // 注意此处是等于，而不是大于等于
                    valid++;
            }
            while (valid == char_table.size()) {
                if (right - left < min_len) {
                    min_len = right - left;
                    min_start = left;
                }
                char left_ch = s[left];
                left++;
                if (char_table.find(left_ch) != char_table.end()) {
                    window[left_ch]--;
                    if (window[left_ch] < char_table[left_ch])
                        valid--;
                }
            }
        }
        return min_len == INT_MAX ? "" : s.substr(min_start, min_len);
    }
};

int main() {
    SolutionV2 s;
    std::cout << s.minWindow("cabwefgewcwaefgcf", "cae") << std::endl;
    std::cout << s.minWindow("ADOBECODEBANC", "ABC") << std::endl;
    std::cout << s.minWindow("a", "a") << std::endl;
    std::cout << s.minWindow("a", "aa") << std::endl;
    return 0;
}
