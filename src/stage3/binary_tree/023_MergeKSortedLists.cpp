/**
 * 23. Merged k Sorted Lists
 * Source: https://leetcode-cn.com/problems/binary-tree-preorder-traversal/
 */

#include <iostream>
#include <vector>
#include <queue>

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 使用优先级队列
// 时间复杂度O(Nlogk) (N为这些链表的节点总数，logk为每个元素在优先级队列中的插入或删除的时间复杂度)
// 空间复杂度O(k) (优先级队列的大小)
class SolutionV1 {
public:
    ListNode *mergeKLists(std::vector<ListNode *> &lists) {
        std::priority_queue<ListNode *, std::vector<ListNode *>, cmp> q;
        for (auto &head: lists) {
            if (head)
                q.push(head);
        }
        ListNode dummy, *p = &dummy;
        while (!q.empty()) {
            ListNode *min_node = q.top();
            q.pop();
            p->next = min_node;
            p = p->next;
            if (min_node->next)
                q.push(min_node->next);
        }
        return dummy.next;
    }

private:
    struct cmp {
        bool operator()(ListNode *a, ListNode *b) {
            return a->val > b->val;
        }
    };
};

// 使用二分法两两合并
// 时间复杂度O(Nlogk) (N为这些链表的节点总数)
// 空间复杂度O(logk) (logk为递归时消耗的栈空间)
class SolutionV2 {
public:
    ListNode *mergeKLists(std::vector<ListNode *> &lists) {
        if (lists.size() == 0)
            return nullptr;
        return merge(lists, 0, lists.size() - 1);
    }

private:
    ListNode *merge(const std::vector<ListNode *> &lists, int low, int high) {
        if (low > high)
            return nullptr;
        if (low == high)
            return lists[low];
        int mid = (low + high) / 2;
        auto m1 = merge(lists, low, mid);
        auto m2 = merge(lists, mid + 1, high);
        return mergeTwoLists(m1, m2);
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy, *p = &dummy;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                p->next = l1;
                l1 = l1->next;
            } else {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        p->next = l1 ? l1 : l2;
        return dummy.next;
    }
};

int main() {
    SolutionV2 s;

    int num1[] = {1, 2, 4};
    int num2[] = {1, 3, 5};
    int num3[] = {2, 4, 4};
    ListNode *l1 = new ListNode(num1[0]);
    ListNode *l2 = new ListNode(num2[0]);
    ListNode *l3 = new ListNode(num3[0]);
    ListNode *p1 = l1, *p2 = l2, *p3 = l3;
    for (int i = 1; i < 3; i++) {
        p1->next = new ListNode(num1[i]);
        p1 = p1->next;
        p2->next = new ListNode(num2[i]);
        p2 = p2->next;
        p3->next = new ListNode(num3[i]);
        p3 = p3->next;
    }
    std::vector<ListNode *> lists = {l1, l2, l3};
    ListNode *ans = s.mergeKLists(lists);
    while (ans) {
        std::cout << ans->val << "->";
        ans = ans->next;
    }
    std::cout << std::endl;
    return 0;
}
