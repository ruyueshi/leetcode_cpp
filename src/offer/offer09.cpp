/**
 * offer 09. 用两个栈实现队列
 * Source: https://leetcode-cn.com/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof/
 */

#include <iostream>
#include <stack>

class CQueueV1 {
public:
    CQueueV1(): s1(), s2() {}

    void appendTail(int value) {
        std::stack<int> *p1, *p2;  // p1是指向空的栈，p2指向非空的栈
        if (this->s1.empty()) {
            p1 = &this->s1;
            p2 = &this->s2;
        } else {
            p1 = &this->s2;
            p2 = &this->s1;
        }

        while (!p2->empty()) {
            p1->push(p2->top());
            p2->pop();
        }
        p1->push(value);
        while (!p1->empty()) {
            p2->push(p1->top());
            p1->pop();
        }
    }

    int deleteHead() {
        if (this->s1.empty() && this->s2.empty()) {
            return -1;
        } else {
            std::stack<int> *p = this->s1.empty() ? &this->s2 : &this->s1;
            int v = p->top();
            p->pop();
            return v;
        }
    }

private:
    std::stack<int> s1, s2;
};

// 改进V1
class CQueueV2 {
public:
    CQueueV2(): s1(), s2(), need_reverse(false) {}

    void appendTail(int value) {
        std::stack<int> *p1, *p2;  // p1是指向空的栈，p2指向非空的栈
        if (this->s1.empty()) {
            p1 = &this->s1;
            p2 = &this->s2;
        } else {
            p1 = &this->s2;
            p2 = &this->s1;
        }

        if (need_reverse) {
            p2->push(value);
        } else {
            while (!p2->empty()) {
                p1->push(p2->top());
                p2->pop();
            }
            p1->push(value);
            this->need_reverse = true;
        }
    }

    int deleteHead() {
        if (this->s1.empty() && this->s2.empty()) {
            return -1;
        } else {
            std::stack<int> *p1, *p2;  // p1是指向空的栈，p2指向非空的栈
            if (this->s1.empty()) {
                p1 = &this->s1;
                p2 = &this->s2;
            } else {
                p1 = &this->s2;
                p2 = &this->s1;
            }
            if (this->need_reverse) {
                while (!p2->empty()) {
                    p1->push(p2->top());
                    p2->pop();
                }
                int v = p1->top();
                p1->pop();
                this->need_reverse = false;
                return v;
            } else {
                int v = p2->top();
                p2->pop();
                return v;
            }
        }
    }

private:
    std::stack<int> s1, s2;
    bool need_reverse;
};

// 参考题解的思路
class CQueueV3 {
public:
    CQueueV3(): s1(), s2() {}

    void appendTail(int value) {
        this->s1.push(value);
    }

    int deleteHead() {
        if (this->s2.empty()) {
            if (this->s1.empty()) {
                return -1;
            } else {
                while (!this->s1.empty()) {
                    this->s2.push(this->s1.top());
                    this->s1.pop();
                }
            }
        }
        int v = this->s2.top();
        this->s2.pop();
        return v;
    }

private:
    std::stack<int> s1, s2;
};

int main() {
    CQueueV3* obj = new CQueueV3();
    std::cout << obj->deleteHead() << std::endl;
    obj->appendTail(1);
    obj->appendTail(2);
    obj->appendTail(3);
    std::cout << obj->deleteHead() << std::endl;
    return 0;
}
