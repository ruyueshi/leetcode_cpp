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

#include "src/utils/timer.h"

class solution030 {
public:
    // overtime
    static std::vector<int> findSubstring(std::string s, std::vector<std::string> &words) {
        int s_len = s.length(), words_num = words.size(), word_len = words[0].length();
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
    static std::vector<int> findSubstring_v2(const std::string &s, std::vector<std::string> &words) {
        size_t s_len = s.length(), words_num = words.size(), word_len = words[0].length();
        if (s_len < words_num * word_len)
            return std::vector<int>();

        size_t traverse_num = s_len - words_num * word_len + 1;
        std::vector<int> res;
        std::map<std::string, std::vector<size_t>> poses_of_words;  // 记录每个单词在words中出现的位置
        for (size_t i = 0; i < words_num; i++) {
            poses_of_words[words[i]].push_back(i);
        }

        for (size_t p = 0; p < word_len; p++) {
            size_t i = p; // 起始位置
            std::map<std::string, size_t> current_pos_of_words;  // 记录各个单词当前的最新位置
            std::vector<size_t> index(words_num, -1);  // 记录当前窗口的各个子串在words中出现的位置
            for (size_t j = 0; j < words_num; j++) {
                std::string substring = s.substr(i + j * word_len, word_len);
                for (int k = 0; k < words_num; k++) {
                    if (substring == words[k]) {
                        size_t next_pos = 0;
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
            std::set<size_t> set_index(index.begin(), index.end());
            if (set_index.size() == words_num && set_index.find(-1) == set_index.end()) {
                res.push_back(static_cast<int>(i));
            }

            // 接下来，每次往后移动一个单词长度的距离
            i += word_len;
            while (i < traverse_num) {
                index.erase(index.begin());
                index.push_back(-1);
                size_t j = words_num - 1;
                std::string substring = s.substr(i + j * word_len, word_len);
                for (int k = 0; k < words_num; k++) {
                    if (substring == words[k]) {
                        size_t next_pos = 0;
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
                set_index = std::set<size_t>(index.begin(), index.end());
                if (set_index.size() == words_num && set_index.find(-1) == set_index.end()) {
                    res.push_back(static_cast<int>(i));
                }

                i += word_len;
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
        auto res = solution030::findSubstring_v2(W[i], L[i]);
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

