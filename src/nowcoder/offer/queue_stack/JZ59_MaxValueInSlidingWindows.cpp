/**
 * JZ59 滑动窗口的最大值
 * Source: https://www.nowcoder.com/practice/1624bc35a45c42c0bc17d17fa0cba788?tpId=13&tqId=23458&ru=/exam/oj/ta&qru=/ta/coding-interviews/question-ranking&sourceUrl=%2Fexam%2Foj%2Fta%3Fpage%3D1%26tpId%3D13%26type%3D13
 */

#include "src/utils/print.h"

#include <queue>

class SolutionV1 {
public:
    std::vector<int> maxInWindows(const std::vector<int> &num, unsigned int size) {
        if (size == 0 || size > num.size()) {
            return {};
        }
        std::vector<int> max_res(num.size() - size + 1);
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, cmp> p;
        for (int i = 0; i < size; i++) {
            p.push({num[i], i});
        }
        max_res[0] = p.top().first;
        for (int i = 1; i <= num.size() - size; i++) {
            p.push({num[i + size - 1], i + size - 1});
            while (p.top().second < i) {
                p.pop();
            }
            max_res[i] = p.top().first;
        }
        return max_res;
    }

private:
    struct cmp {
        bool operator()(std::pair<int, int> a, std::pair<int, int> b) {
            return a.first < b.first;
        }
    };
};

class SolutionV2 {
public:
    std::vector<int> maxInWindows(const std::vector<int> &num, unsigned int size) {
        if (size == 0 || size > num.size()) {
            return {};
        }
        std::vector<int> max_res(num.size() - size + 1);
        std::deque<int> q;
        for (int i = 0; i < size; i++) {
            while (!q.empty() && num[q.back()] < num[i]) {
                q.pop_back();
            }
            q.push_back(i);
        }
        max_res[0] = num[q.front()];
        for (int i = size; i < num.size(); i++) {
            while (!q.empty() && num[q.back()] < num[i]) {
                q.pop_back();
            }
            q.push_back(i);
            if (q.front() <= i - size) {
                q.pop_front();
            }
            max_res[i - size + 1] = num[q.front()];
        }
        return max_res;
    }

};

int main() {
    SolutionV2 s;
    print_vector(s.maxInWindows({2, 3, 4, 2, 6, 2, 5, 1}, 3));
    return 0;
}
