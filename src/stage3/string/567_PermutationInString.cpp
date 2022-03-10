/**
 * 567. Permutation in String
 * Source: https://leetcode-cn.com/problems/permutation-in-string/
 */

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

// 滑动窗口
class SolutionV1 {
public:
    bool checkInclusion(std::string s1, std::string s2) {
        std::unordered_map<char, int> need, window;
        for (const auto &c: s1)
            need[c]++;
        int left = 0, right = 0;
        while (right < s2.size()) {
            char ch_right = s2[right];
            if (need.find(ch_right) != need.end()) {
                window[ch_right]++;
            }
            if (need == window)
                return true;
            if (right - left + 1 == s1.size()) {
                char ch_left = s2[left];
                left++;
                if (need.find(ch_left) != need.end()) {
                    window[ch_left]--;
                }
            }
            right++;
        }
        return false;
    }
};

class SolutionV2 {
public:
    bool checkInclusion(std::string s1, std::string s2) {
        if (s1.size() > s2.size())
            return false;
        std::vector<int> need(26, 0), window(26, 0);
        int m = s1.size();
        for (int i = 0; i < m; i++) {
            need[s1[i] - 'a']++;
            window[s2[i] - 'a']++;
        }
        if (need == window)
            return true;
        for (int i = m; i < s2.size(); i++) {
            window[s2[i] - 'a']++;
            window[s2[i - m] - 'a']--;
            if (need == window)
                return true;
        }
        return false;
    }
};

int main() {
    SolutionV2 s;
    std::cout << s.checkInclusion("ab", "eidbaooo") << std::endl;
    std::cout << s.checkInclusion("ab", "eidboaoo") << std::endl;
    std::cout << s.checkInclusion("abcdxabcde", "abcdeabcdx") << std::endl;
    return 0;
}
