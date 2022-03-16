/**
 * 19. Remove Nth Node From End of List
 * Source: https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/
 */

#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 双指针
class SolutionV1 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast = head;
        int i = 0;
        for (; i <= n; i++) { // 走n+1步
            if (!fast)
                break;
            fast = fast->next;
        }
        if (i <= n) { // 说明n等于head的长度
            ListNode *temp = head->next;
            delete head;
            return temp;
        }

        ListNode *slow = head;
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode *temp = slow->next;
        slow->next = slow->next->next;
        delete temp;
        return head;
    }
};

// 优化V1
// 更加优雅
class SolutionV2 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(-1, head);
        auto target = findNthFromEnd(&dummy, n + 1);
        auto to_del = target->next;
        target->next = target->next->next;
        delete to_del;
        to_del = nullptr;
        return dummy.next;
    }

private:
    ListNode* findNthFromEnd(ListNode* head, int n) {
        ListNode *fast = head, *slow = head;
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};

int main() {
    SolutionV2 s;

    int num[] = {1, 2, 4};
    ListNode *l = new ListNode(num[0]);
    ListNode *p = l;
    for (int i = 1; i < 3; i++) {
        p->next = new ListNode(num[i]);
        p = p->next;
    }
    ListNode *ans = s.removeNthFromEnd(l, 3);
    while (ans) {
        std::cout << ans->val << "->";
        ans = ans->next;
    }
    std::cout << std::endl;
    return 0;
}

