/**
 * JZ86 在二叉树中找到两个节点的最近公共祖先
 * Source: https://www.nowcoder.com/practice/e0cc33a83afe4530bcec46eba3325116?tpId=13&tqId=1024325&ru=/exam/oj/ta&qru=/ta/coding-interviews/question-ranking&sourceUrl=%2Fexam%2Foj%2Fta%3Fpage%3D1%26tpId%3D13%26type%3D13
 */

#include <iostream>
#include <unordered_map>

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param str string字符串
     * @param pattern string字符串
     * @return bool布尔型
     */
    bool match(std::string str, std::string pattern) {
        // write code here
        m = str.length(), n = pattern.length();
        return dp(str, pattern, 0, 0);
    }

private:
    int m, n;
    std::unordered_map<std::string, bool> record;

    bool dp(const std::string &str, const std::string& pattern, int i, int j) {
        if ( j == n) {
            return i == m;
        }
        if (i == m) {
            if ((n - j) % 2 == 1) {
                return false;
            }
            for (; j < n; j += 2) {
                if (pattern[j + 1] != '*') {
                    return false;
                }
            }
            return true;
        }

        std::string key = std::to_string(i) + "-" + std::to_string(j);
        if (record.find(key) != record.end()) {
            return record[key];
        }

        bool res;
        if (str[i] == pattern[j] || pattern[j] == '.') {
            if (j < n - 1 && pattern[j + 1] == '*') {
                res = dp(str, pattern, i, j + 2) || dp(str, pattern, i + 1, j);
            } else {
                res = dp(str, pattern, i + 1, j + 1);
            }
        } else {
            if (j < n - 1 && pattern[j + 1] == '*') {
                res = dp(str, pattern, i, j + 2);
            } else {
                res = false;
            }
        }
        record[key] = res;
        return res;
    }
};

int main() {
    Solution s;
    std::cout << s.match("aaaa", "aaac*") << std::endl;
    return 0;
}
