/*
 * 13. Roman to Integer
 * Source: https://leetcode-cn.com/problems/roman-to-integer/
 */

#ifndef SOLUTION013_H
#define SOLUTION013_H

#include <iostream>
#include <map>
#include <vector>

class solution013 {
public:
    // 136ms, 15.9MB
    int romanToInt1(std::string s) {
        std::map<std::string, int> score;
        std::vector<std::string> keys = {"I", "V", "X", "L", "C", "D", "M", "IV", "IX", "XL", "XC", "CD", "CM"};
        std::vector<int> values = {1, 5, 10, 50, 100, 500, 1000, 4, 9, 40, 90, 400, 900};
        for (size_t i = 0; i < keys.size(); i++) {
            score.insert({keys[i], values[i]});
        }

        int res = 0;
        size_t i = 0;
        while (i < s.length()) {
            switch (s[i]) {
            case 'I':
            case 'X':
            case 'C': {
                std::string key;
                if (i + 1 < s.length() && score.find(key.assign(s, i, 2)) != score.end()) {
                    res += score[key];
                    i += 2;
                    break;
                }
            }
            default: {
                res += score[std::string(1, s[i])];
                i += 1;
                break;
            }
            }
        }
        return res;
    }

    // 80ms, 16MB
    int romanToInt2(std::string s) {
        std::map<std::string, int> score;
        std::vector<std::string> keys = {"I", "V", "X", "L", "C", "D", "M", "IV", "IX", "XL", "XC", "CD", "CM"};
        std::vector<int> values = {1, 5, 10, 50, 100, 500, 1000, 4, 9, 40, 90, 400, 900};
        for (size_t i = 0; i < keys.size(); i++) {
            score.insert({keys[i], values[i]});
        }

        int res = 0;
        size_t i = 0;
        while (i < s.length()) {
            switch (s[i]) {
            case 'I': {
                std::string key;
                if (i + 1 < s.length() && (s[i+1] == 'V' || s[i+1] == 'X')) {
                    res += score[key.assign(s, i, 2)];
                    i += 2;
                } else {
                    res += score[std::string(1, s[i])];
                    i += 1;
                }
                break;
            }
            case 'X': {
                std::string key;
                if (i + 1 < s.length() && (s[i+1] == 'L' || s[i+1] == 'C')) {
                    res += score[key.assign(s, i, 2)];
                    i += 2;
                } else {
                    res += score[std::string(1, s[i])];
                    i += 1;
                }
                break;
            }
            case 'C': {
                std::string key;
                if (i + 1 < s.length() && (s[i+1] == 'D' || s[i+1] == 'M')) {
                    res += score[key.assign(s, i, 2)];
                    i += 2;
                } else {
                    res += score[std::string(1, s[i])];
                    i += 1;
                }
                break;
            }
            default: {
                res += score[std::string(1, s[i])];
                i += 1;
                break;
            }
            }
        }
        return res;
    }

    // good
    int romanToInt3(std::string s) {
        int ans = 0;
        int pre = get_value(s[0]);
        for (size_t i = 1; i < s.length(); i++) {
            int temp = this->get_value(s[i]);
            if (pre < temp) {
                ans -= pre;
            } else {
                ans += pre;
            }
            pre = temp;
        }
        ans += pre;
        return ans;
    }

private:
    int get_value(char key) {
        switch (key) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }
};

void test_solution013() {
    solution013 s;
    std::cout << s.romanToInt2("III") << std::endl;
    std::cout << s.romanToInt2("IV") << std::endl;
    std::cout << s.romanToInt2("IX") << std::endl;
    std::cout << s.romanToInt2("LVIII") << std::endl;
    std::cout << s.romanToInt3("MCMXCIV") << std::endl;
}

#endif // SOLUTION013_H
