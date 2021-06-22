/**
 * 30. Substring with Concatenation of All Words
 * Source: https://leetcode-cn.com/problems/substring-with-concatenation-of-all-words/
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

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

    // v1中会有很多重复查找的过程，在v2中设置标志位，一旦查找完一轮，往下滑动一个单词长度的距离，只需比较新出现的子串是否是候选单词
    static std::vector<int> findSubstring_v2(std::string s, std::vector<std::string> &words) {
        int s_len = s.length(), words_num = words.size(), word_len = words[0].length();
        if (s_len < words_num * word_len)
            return std::vector<int>();

        int traverse_num = s_len - words_num * word_len + 1;
        std::vector<int> res;
        for (int p = 0; p < word_len; p++) {
            int i = p; // 起始位置
            std::vector<int> flags(words_num, 0);  // 0 1 2 三个档位
            std::vector<int> index(words_num, -1);
            for (int j = 0; j < words_num; j++) {
                std::string substring = s.substr(i + j * word_len, word_len);
                std::vector<int> pos;
                for (int k = 0; k < words_num; k++) {
                    if (words[k] == substring) {
                        pos.push_back(k);
                        if (flags[k] == 0) {
                            flags[k] = 1;
                            index[j] = k;
                            break;
                        }
                        index[j] = pos[0];
                    }
                }
            }
            if (std::accumulate(flags.begin(), flags.end(), 0) == words_num)
                res.push_back(i);

            i += word_len;
            while (i < traverse_num) {
                int first = index[0];
                auto same = std::find(index.begin() + 1, index.end(), first);
                if (first != -1 && same == index.end()) {
                    flags[first] = false;
                }
                index.erase(index.begin());
                index.push_back(-1);

                int j = words_num - 1;
                std::string substring = s.substr(i + j * word_len, word_len);
                std::vector<int> pos;
                for (int k = 0; k < words_num; k++) {
                    if (words[k] == substring) {
                        pos.push_back(k);
                        if (flags[k] == 0) {
                            flags[k] = 1;
                            index[j] = k;
                            break;
                        }
                        index[j] = pos[0];
                    }
                }
                if (std::accumulate(flags.begin(), flags.end(), 0) == words_num)
                    res.push_back(i);

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

