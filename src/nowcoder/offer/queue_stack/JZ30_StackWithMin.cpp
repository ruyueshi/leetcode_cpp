/**
 * JZ30 包含min函数的栈
 * Source: https://www.nowcoder.com/practice/4c776177d2c04c2494f2555c9fcc1e49?tpId=13&tqId=23268&ru=/exam/oj/ta&qru=/ta/coding-interviews/question-ranking&sourceUrl=%2Fexam%2Foj%2Fta%3Fpage%3D1%26tpId%3D13%26type%3D13
 */

#include <stack>

class Solution {
public:
    void push(int value) {
        s1.push(value);
        if (s2.empty() || value <= s2.top()) {
            s2.push(value);
        }
    }
    void pop() {
        if (s1.top() == s2.top()) {
            s2.pop();
        }
        s1.pop();
    }
    int top() {
        return s1.top();
    }
    int min() {
        return s2.top();
    }

private:
    std::stack<int> s1, s2;
};
