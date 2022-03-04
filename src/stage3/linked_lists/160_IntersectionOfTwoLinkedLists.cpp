/**
 * 160. Intersection of Two Linked Lists
 * Source: https://leetcode-cn.com/problems/intersection-of-two-linked-lists/
 */

#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class SolutionV1 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a = headA, *b = headB;
        while (a != b) {
            a = a ? a->next : headB;
            b = b ? b->next : headA;
        }
        return a;
    }
};

// 优化V1
class SolutionV2 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *tail = nullptr;  // 尾节点存储a和b的尾节点，如果两个链表不相交，可提前停止循环。
        ListNode *a = headA, *b = headB;
        while (a != b) {
            if (a->next)
                a = a->next;
            else {
                if (tail && tail != a)
                    return nullptr;
                tail = a;
                a = headB;
            }
            if (b->next)
                b = b->next;
            else {
                if (tail && tail != b)
                    return nullptr;
                tail = b;
                b = headA;
            }
        }
        return a;
    }
};

int main() {
    SolutionV2 s;
    ListNode *head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(4);
    ListNode *head2 = new ListNode(1);
    head2->next = head1->next;
    auto res = s.getIntersectionNode(head1, head2);
    if (res)
        std::cout << res->val << std::endl;
    return 0;
}

