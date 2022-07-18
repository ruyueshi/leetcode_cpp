/**
 * JZ6. 从尾到头打印链表元素
 * Source: https://www.nowcoder.com/practice/d0267f7f55b3412ba93bd35cfa8e8035?tpId=13&tqId=23278&ru=/exam/oj/ta&qru=/ta/coding-interviews/question-ranking&sourceUrl=%2Fexam%2Foj%2Fta%3Fpage%3D1%26tpId%3D13%26type%3D13
 */

#include <iostream>
#include <stack>
#include <vector>

#include "src/utils/print.h"

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};


class SolutionV1 {
public:
    std::vector<int> printListFromTailToHead(ListNode* head) {
        std::stack<int> s;
        std::vector<int> res;
        auto p = head;
        while (p) {
            s.push(p->val);
            p = p->next;
        }
        while (!s.empty()) {
            res.push_back(s.top());
            s.pop();
        }
        return res;
    }
};

class SolutionV2 {
public:
    std::vector<int> printListFromTailToHead(ListNode* head) {
        std::vector<int> res;
        recursion(head, res);
        return res;
    }

private:
    void recursion(ListNode* head, std::vector<int> &res) {
        if (!head) {
            return;
        }
        recursion(head->next, res);
        res.push_back(head->val);
    }
};

int main() {
    SolutionV2 s;
    auto* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    print_vector(s.printListFromTailToHead(head));
    return 0;
}
