/**
 * JZ35. 复杂链表的复制
 * Source: https://www.nowcoder.com/practice/f836b2c43afc4b35ad6adc41ec941dba?tpId=13&tqId=23254&ru=/exam/oj/ta&qru=/ta/coding-interviews/question-ranking&sourceUrl=%2Fexam%2Foj%2Fta%3Fpage%3D1%26tpId%3D13%26type%3D13
 */

#include <iostream>
#include <unordered_map>

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};

class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead) {
        std::unordered_map<RandomListNode*, RandomListNode*> m;  // record random node
        auto p1 = pHead;
        RandomListNode dummy(-1);
        auto p2 = &dummy;
        while (p1) {
            p2->next = new RandomListNode(p1->label);
            m[p1] = p2->next;
            p1 = p1->next;
            p2 = p2->next;
        }
        p1 = pHead, p2 = dummy.next;
        while (p1) {
            p2->random = m[p1->random];
            p1 = p1->next;
            p2 = p2->next;
        }
        return dummy.next;
    }
};

int main() {
    Solution s;
    RandomListNode *random_list[5];
    int input[10] = {1,2,3,4,5,3,5,-1,2,-1};
    random_list[0] = new RandomListNode(input[0]);
    RandomListNode *head = random_list[0];
    for (int i = 1; i < 5; i++) {
        random_list[i] = new RandomListNode(input[i]);
        random_list[i-1]->next = random_list[i];
    }
    for (int i = 5; i < 10; i++) {
        if (input[i] == -1) {
            random_list[i-5]->random = nullptr;
        } else {
            random_list[i-5]->random = random_list[input[i]-1];
        }
    }
    auto res = s.Clone(head);
    while (res) {
        std::cout << "label: " << res->label
                  << ", next: " << (res->next ? res->next->label : -1)
                  << ", random: " << (res->random ? res->random->label : -1)
                  << std::endl;
        res = res->next;
    }
    return 0;
}
