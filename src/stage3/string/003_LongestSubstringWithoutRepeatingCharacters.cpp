/**
 * 3. Longest Substring Without Repeating Characters
 * Source: https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/
 */

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_set>

class SolutionV1 {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::map<char, int> m;
        int max_len = 0, current_start = 0;
        for (int i = 0; i < s.length(); i++) {
            auto it = m.find(s[i]);
            if (it != m.end())
                current_start = std::max(current_start, it->second + 1);
            m[s[i]] = i;
            max_len = std::max(max_len, (i - current_start + 1));
        }
        return max_len;
    }
};

// V2：网上的解法，速度反而更慢了，占用的空间更多了
class SolutionV2 {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_set<char> table;
        int max_len = 0, current_start = 0;
        for (int i = 0; i < s.length(); i++) {
            while (table.find(s[i]) != table.end()) {
                table.erase(s[current_start]);
                current_start++;
            }
            table.insert(s[i]);
            max_len = std::max(max_len, (i - current_start + 1));
        }
        return max_len;
    }
};

int main() {
    SolutionV1 s;
    std::vector<std::string> test_case = {"abba", "abcabcbb", "bbbbb", "pwwkew"};
    for (const auto &str: test_case) {
        std::cout << s.lengthOfLongestSubstring(str) << std::endl;
    }
    return 0;
}
