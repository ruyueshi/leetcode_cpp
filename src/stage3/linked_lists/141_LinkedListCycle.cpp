/**
 * 141. Linked List Cycle
 * Source: https://leetcode-cn.com/problems/linked-list-cycle/
 */

#include <iostream>
#include <unordered_set>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 使用集合置标志位
// 时间复杂度O(N)
// 空间复杂度O(N)
class SolutionV1 {
public:
    bool hasCycle(ListNode *head) {
        std::unordered_set<ListNode *> s;
        while (head) {
            if (s.find(head) != s.end())
                return true;
            s.insert(head);
            head = head->next;
        }
        return false;
    }
};

// 快慢指针
class SolutionV2 {
public:
    bool hasCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
                return true;
        }
        return false;
    }
};

int main() {
    SolutionV2 s;

    std::vector<int> num = {1, 2, 3, 4};
    ListNode *l = new ListNode(num[0]);
    ListNode *p = l;
    for (int i = 1; i < num.size(); i++) {
        p->next = new ListNode(num[i]);
        p = p->next;
    }
    p->next = l->next->next;
    std::cout << s.hasCycle(l) << std::endl;
    return 0;
}