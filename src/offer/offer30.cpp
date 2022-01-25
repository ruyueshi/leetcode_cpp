/**
 * offer 30. 包含min函数的栈
 * Source: https://leetcode-cn.com/problems/bao-han-minhan-shu-de-zhan-lcof/
 */

#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

class MinStackV1 {
public:
    /** initialize your data structure here. */
    MinStackV1(): v(){

    }

    void push(int x) {
        this->v.push_back(x);
    }

    void pop() {
        this->v.pop_back();
    }

    int top() {
        return this->v.back();
    }

    int min() {
        return *std::min_element(v.begin(), v.end());
    }

private:
    std::vector<int> v;
};

class MinStackV2 {
public:
    /** initialize your data structure here. */
    MinStackV2(): s1(), s2() {

    }

    void push(int x) {
        this->s1.push(x);
        if (this->s2.empty() || x <= this->s2.top()) {
            this->s2.push(x);
        }
    }

    void pop() {
        if (this->s1.top() == this->s2.top()) {
            this->s2.pop();
        }
        this->s1.pop();
    }

    int top() {
        return this->s1.top();
    }

    int min() {
        return this->s2.top();
    }

private:
    std::stack<int> s1, s2;
};

int main() {
    MinStackV2* obj = new MinStackV2();
    obj->push(0);
    obj->push(1);
    obj->push(0);
    std::cout << obj->min() << std::endl;
    obj->pop();
    std::cout << obj->min() << std::endl;
    return 0;
}
