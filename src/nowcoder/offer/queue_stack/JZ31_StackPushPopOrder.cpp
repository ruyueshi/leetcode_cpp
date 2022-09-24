/**
 * JZ31 JZ31 栈的压入、弹出序列
 * Source: https://www.nowcoder.com/practice/d77d11405cc7470d82554cb392585106?tpId=13&tqId=23290&ru=/exam/oj/ta&qru=/ta/coding-interviews/question-ranking&sourceUrl=%2Fexam%2Foj%2Fta%3Fpage%3D1%26tpId%3D13%26type%3D13
 */

#include <iostream>
#include <stack>
#include <unordered_set>
#include <vector>

class Solution {
public:
    bool IsPopOrder(std::vector<int> pushV, std::vector<int> popV) {
        std::stack<int> s;
        std::unordered_set<int> in_stack;
        for (int i = 0, j = 0; j < popV.size(); j++) {
            if (in_stack.find(popV[j]) == in_stack.end()) {
                while (i < pushV.size() && pushV[i] != popV[j]) {
                    s.push(pushV[i]);
                    in_stack.insert(pushV[i]);
                    i++;
                }
                if (i == pushV.size()) {
                    return false;
                }
                i++;
            } else {
                if (popV[j] != s.top()) {
                    return false;
                } else {
                    in_stack.erase(s.top());
                    s.pop();
                }
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    std::cout << s.IsPopOrder({1, 2, 3, 4, 5}, {4, 5, 3, 2, 1}) << std::endl;
    return 0;
}
