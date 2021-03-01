/**
 * 28. Implement strStr()
 * Source: https://leetcode-cn.com/problems/implement-strstr/
 */

#ifndef LEETCODE_CPP_SOLUTION028_H
#define LEETCODE_CPP_SOLUTION028_H

#include <iostream>
#include <string>

class solution028 {
public:
    // 764ms, 6.7MB, brute force matching algorithm (暴力匹配算法)
    int strStr1(std::string haystack, std::string needle) {
        if (needle.empty()) {
            return 0;
        }
        int i = 0;
        while (i < haystack.size()) {
            if (haystack[i] == needle[0]) {
                int j = 1;
                i++;
                while (j < needle.size()) {
                    if (haystack[i] != needle[j]) {
                        break;
                    }
                    i++, j++;
                }
                if (j == needle.size()) {
                    return (i - j);
                } else {
                    i -= j;
                }
            }
            i++;
        }
        return -1;
    }

    // 0ms, 6.8MB, KMP algorithm (It seems pretty awesome)
    int strStr2(std::string haystack, std::string needle) {
        if (needle.empty()) {
            return 0;
        }
        int next[needle.length()];
        this->getNext(next, needle);
        int i = 0, j = 0;
        int haystack_length = haystack.length(), needle_length = needle.length();
        while (i < haystack_length && j < needle_length) {
            if (j == -1 || haystack[i] == needle[j]) {
                i++, j++;
            } else {
                j = next[j];
            }
        }
        return (j == needle.length()) ? (i - j) : -1;
    }

    void getNext(int next[], std::string needle) {
        int j = 0, k = -1, needle_length = needle.length();
        next[0] = -1;
        while (j < needle_length - 1) {
            if (k == -1 || needle[j] == needle[k]) {
                j++, k++;
                next[j] = k; // or next[j] = next[j-1] + 1, because next[j-1] = k-1
            } else {
                k = next[k];
            }
        }
    }
};

static void test_solution028() {
    solution028 s;
    std::string haystack = "mississippi", needle = "issip"; // test case: "mississippi" "issip"
    do {
        std::cout << "Input: haystack = " << haystack << ", needle = " << needle << "\nOutput: "
                  << s.strStr2(haystack, needle) << std::endl;
        std::cin >> haystack >> needle;
    } while (!haystack.empty());
}

#endif //LEETCODE_CPP_SOLUTION028_H