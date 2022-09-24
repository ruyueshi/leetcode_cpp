/**
 * JZ73 翻转单词序列
 * Source: https://www.nowcoder.com/practice/3194a4f4cf814f63919d0790578d51f3?tpId=13&tqId=23287&ru=/exam/oj/ta&qru=/ta/coding-interviews/question-ranking&sourceUrl=%2Fexam%2Foj%2Fta%3Fpage%3D1%26tpId%3D13%26type%3D13
 */

#include <iostream>
#include <stack>
#include <unordered_set>
#include <vector>

class Solution {
public:
    std::string ReverseSentence(std::string str) {
        if (str.length() == 0) {
            return "";
        }
        std::string res;
        int start = 0;
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == ' ') {
                res = str.substr(start, i - start) + " " + res;
                start = i + 1;
            } else if (i == str.length() - 1) {
                res = str.substr(start, i - start + 1) + " " + res;
            }
        }
        res.erase(res.end() - 1);
        return res;
    }
};

int main() {
    Solution s;
    std::cout << s.ReverseSentence("nowcoder. a am I") << std::endl;
    return 0;
}
