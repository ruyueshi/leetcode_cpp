/**
 * 30. Substring with Concatenation of All Words
 * Source: https://leetcode-cn.com/problems/substring-with-concatenation-of-all-words/
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <unordered_map>
#include "src/utils/timer.h"

class solution030 {
public:
    // overtime
    static std::vector<int> findSubstring_v1(std::string s, std::vector<std::string> &words) {
        int s_len = s.length(), words_num = words.size(), word_len = words[0].length();
        if (s.empty() || words.empty() || s_len < words_num * word_len)
            return {};

        int traverse_num = s_len - words_num * word_len + 1;
        std::vector<int> res;
        for (int i = 0; i < traverse_num; i++) {
            std::vector<int> flags(words_num, 0);
            for (int j = 0; j < words_num; j++) {
                std::string substring = s.substr(i + j * word_len, word_len);
                // words中可能有重复的单词，需添加标志变量来避免重复查找
                int k = 0;
                auto pos = std::find_if(words.begin(), words.end(), [substring, flags, &k](const std::string &word) { return !flags[k++] && word == substring; });
                if (pos == words.end())
                    break;
                else
                    flags[pos - words.begin()] = 1;
            }
            if (std::accumulate(flags.begin(), flags.end(), 0) == words_num)
                res.push_back(i);
        }
        return res;
    }

    // v1中会有很多重复查找的过程，在v2中设置标志位，一旦查找完一轮，往后滑动一个单词长度的距离，只需比较新出现的子串是否是候选单词
    // 756 ms, 16%; 97.4 MB, 17%
    static std::vector<int> findSubstring_v2(const std::string &s, std::vector<std::string> &words) {
        int s_len = s.length(), words_num = words.size(), word_len = words[0].length();
        if (s.empty() || words.empty() || s_len < words_num * word_len)
            return {};

        int traverse_num = s_len - words_num * word_len + 1;
        std::vector<int> res;
        std::unordered_map<std::string, std::vector<int>> poses_of_words;  // 记录每个单词在words中出现的位置
        for (int i = 0; i < words_num; i++) {
            poses_of_words[words[i]].push_back(i);
        }

        for (int p = 0; p < word_len; p++) {
            int i = p; // 起始位置
            std::unordered_map<std::string, int> current_pos_of_words;  // 记录各个单词当前的最新位置
            std::vector<int> index(words_num, -1);  // 记录当前窗口的各个子串在words中出现的位置
            for (int j = 0; j < words_num; j++) {
                std::string substring = s.substr(i + j * word_len, word_len);
                for (int k = 0; k < words_num; k++) {
                    if (substring == words[k]) {
                        int next_pos = 0;
                        auto it = current_pos_of_words.find(substring);
                        if (it != current_pos_of_words.end()) {
                            next_pos = (it->second + 1) % poses_of_words[substring].size();
                        }
                        index[j] = poses_of_words[substring][next_pos];
                        current_pos_of_words[substring] = next_pos;
                        break;
                    }
                }
            }
            // 判断 index 是否构成符合题意的解
            std::set<int> set_index(index.begin(), index.end());
            if (set_index.size() == words_num && set_index.find(-1) == set_index.end()) {
                res.push_back(i);
            }

            // 接下来，每次往后移动一个单词长度的距离
            i += word_len;
            while (i < traverse_num) {
                index.erase(index.begin());
                index.push_back(-1);
                int j = words_num - 1;
                std::string substring = s.substr(i + j * word_len, word_len);
                for (int k = 0; k < words_num; k++) {
                    if (substring == words[k]) {
                        int next_pos = 0;
                        auto it = current_pos_of_words.find(substring);
                        if (it != current_pos_of_words.end()) {
                            next_pos = (it->second + 1) % poses_of_words[substring].size();
                        }
                        index[j] = poses_of_words[substring][next_pos];
                        current_pos_of_words[substring] = next_pos;
                        break;
                    }
                }
                // 判断 index 是否构成符合题意的解
                set_index.clear();
                set_index = std::set<int>(index.begin(), index.end());
                if (set_index.size() == words_num && set_index.find(-1) == set_index.end()) {
                    res.push_back(i);
                }

                i += word_len;
            }
        }
        return res;
    }

    // v2 建立单词到单词位置的映射，统计各个窗口中匹配到的单词出现的位置，匹配过程中记录单词的位置会比较繁琐，因为words中的重复单词，我们没必要知道他们的区别，计算匹配个数就可以了。
    // 因此 v3 的做法是统计单词的个数，需要建立单词到单词出现次数的映射
    // 32 ms, 94.21%; 16.2MB, 75.25%
    static std::vector<int> findSubstring_v3(const std::string &s, std::vector<std::string> &words) {
        int s_len = s.length(), words_num = words.size(), word_len = words[0].length();
        if (s.empty() || words.empty() || s_len < words_num * word_len)
            return {};

        int traverse_num = s_len - words_num * word_len + 1;
        std::vector<int> res;
        std::unordered_map<std::string, int> map_word_count;  // 记录每个单词在words中出现的次数
        for (int i = 0; i < words_num; i++)
            map_word_count[words[i]]++;

        for (int i = 0; i < word_len; i++) {
            int left = i, right = i, count = 0;  // left 和 right 为滑动窗口的左右边界（和v2不同，v3这里的滑动窗口里边的单词都是目标单词，因此滑动窗口的长度小于等于 word_len*words_num ）
            std::unordered_map<std::string, int> temp_map;  // 记录滑动窗口中单词以及单词的出现次数
            while (right < s_len) {
                std::string substring = s.substr(right, word_len);
                right += word_len;  // 和 v2 一样，每次滑动一个单词的长度
                if (map_word_count.find(substring) == map_word_count.end()) {
                    left = right;
                    count = 0;
                    temp_map.clear();
                } else {
                    count++;
                    temp_map[substring]++;
                    // v3 处理重复单词的关键所在：一旦滑动窗口新增的单词 substring 的数量超过 words 中对应的单词的数量，则滑动窗口一定不满足条件，做法是：
                    // 由于不知道 substring 在滑动窗口中的位置，只能从左往右逐个排除（由此想到，设置一个变量来记录每个串出现的位置，那么就省去下面的循环查找了，可以在 v4 中试试看）
                    while (temp_map[substring] > map_word_count[substring]) {
                        std::string first_string = s.substr(left, word_len);
                        count--;
                        temp_map[first_string]--;
                        left += word_len;
                    }
                    if (count == words_num)
                        res.push_back(left);
                }
            }
        }

        return res;
    }
};

int main() {
    std::vector<std::vector<std::string>> L = {{"foo",  "bar"},
                                               {"a",    "b",    "c",    "d",  "e"},
                                               {"mon",  "key"},
                                               {"fooo", "barr", "ding", "wing"},
                                               {"word", "good", "best", "good"},
                                               {"c",    "b",    "a",    "c",  "a",  "a",  "a",  "b",  "c"},
                                               {"ab",   "ba",   "ab",   "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab",
                                                       "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba",
                                                       "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab",
                                                       "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba",
                                                       "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab",
                                                       "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba",
                                                       "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab",
                                                       "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba",
                                                       "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab",
                                                       "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba",
                                                       "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab",
                                                       "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba",
                                                       "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab",
                                                       "ba", "ab", "ba", "ab", "ba"}};
    std::vector<std::string> W = {"barfoothefoobarman",
                                  "abcdfecdba",
                                  "monkey",
                                  "lingmindraboofooowingdingbarrwingmonkeypoundcake",
                                  "wordgoodgoodgoodbestword",
                                  "bcabbcaabbccacacbabccacaababcbb",
                                  "abababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababab"};
    timer t;
    for (int i = 0; i < L.size(); i++) {
        std::cout << "============================\n";
        t.reset();
        auto res = solution030::findSubstring_v3(W[i], L[i]);
        double diff = t.cost();
        std::cout << "Input: W=\"" << W[i] << "\", L=[";
        std::for_each(L[i].begin(), L[i].end(), [](const std::string &s) { std::cout << "\"" << s << "\","; });
        std::cout << "\b]\nOutput: ";
        std::for_each(res.begin(), res.end(), [](const int &pos) { std::cout << pos << " "; });
        std::cout << "\n";
        std::cout << "cost time: " << diff << "ms" << std::endl;
    }
    return 0;
}

