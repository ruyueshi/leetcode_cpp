/**
 * 438. Find All Anagrams in a String
 * Source: https://leetcode-cn.com/problems/find-all-anagrams-in-a-string/
 */

#include <string>
#include <vector>

#include "src/utils/print.h"

class Solution {
public:
    std::vector<int> findAnagrams(std::string s, std::string p) {
        if (s.size() < p.size())
            return {};
        std::vector<int> need(26, 0), window(26, 0);
        std::vector<int> res;
        int n = p.size();
        for (int i = 0; i < n; i++) {
            need[p[i] - 'a']++;
            window[s[i] - 'a']++;
        }
        if (need == window)
            res.push_back(0);
        for (int i = n; i < s.size(); i++) {
            window[s[i] - 'a']++;
            window[s[i - n] - 'a']--;
            if (need == window)
                res.push_back(i - n + 1);
        }
        return res;
    }
};

int main() {
    Solution s;
    print_vector(s.findAnagrams("cbaebabacd", "abc"));
    print_vector(s.findAnagrams("abab", "ab"));
    print_vector(s.findAnagrams("abcdxabcde", "abcdeabcdx"));
    return 0;
}
