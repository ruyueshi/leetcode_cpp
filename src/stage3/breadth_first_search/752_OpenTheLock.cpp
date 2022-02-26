/**
 * 752. Open the Lock
 * Source: https://leetcode-cn.com/problems/open-the-lock/
 */

#include <iostream>
#include <queue>
#include <unordered_set>
#include <string>
#include <vector>
#include <algorithm>

class SolutionV1 {
public:
    int openLock(std::vector<std::string> &deadends, std::string target) {
        std::string cur = "0000";
        std::queue<std::string> q;
        std::unordered_set<std::string> visited;
        q.push(cur);
        visited.insert(cur);
        int step = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                cur = q.front();
                q.pop();
                if (std::find(deadends.begin(), deadends.end(), cur) != deadends.end())
                    continue;
                if (cur == target)
                    return step;
                for (int j = 0; j < 4; j++) {
                    char ch = cur[j];
                    // 向上翻滚
                    cur[j] = (ch - '0' + 1) % 10 + '0';
                    if (visited.find(cur) == visited.end()) {
                        q.push(cur);
                        visited.insert(cur);
                    }
                    // 向下翻滚
                    cur[j] = (ch - '0' + 9) % 10 + '0';
                    if (visited.find(cur) == visited.end()) {
                        q.push(cur);
                        visited.insert(cur);
                    }
                    cur[j] = ch;
                }
            }
            step++;
        }
        return -1;
    }
};

class SolutionV2 {
public:
    int openLock(std::vector<std::string> &deadends, std::string target) {
        std::string cur = "0000";
        std::queue<std::string> q;
        std::unordered_set<std::string> visited(deadends.begin(), deadends.end());
        if (visited.count(cur) > 0)
            return -1;
        q.push(cur);
        visited.insert(cur);
        int step = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                cur = q.front();
                q.pop();
                if (cur == target)
                    return step;
                for (int j = 0; j < 4; j++) {
                    char ch = cur[j];
                    // 向上翻滚
                    cur[j] = ch == '9' ? '0' : ch + 1;
                    if (visited.count(cur) == 0) {
                        q.push(cur);
                        visited.insert(cur);
                    }
                    // 向下翻滚
                    cur[j] = ch == '0' ? '9' : ch - 1;
                    if (visited.count(cur) == 0) {
                        q.push(cur);
                        visited.insert(cur);
                    }
                    cur[j] = ch;
                }
            }
            step++;
        }
        return -1;
    }
};

class SolutionV3 {
public:
    int openLock(std::vector<std::string> &deadends, std::string target) {
        std::unordered_set<std::string> visited(deadends.begin(), deadends.end());
        std::unordered_set<std::string> q1, q2;
        if (visited.count("0000") > 0)
            return -1;
        q1.insert("0000");
        q2.insert(target);
        int step = 0;
        while (!q1.empty() && !q2.empty()) {
            std::unordered_set<std::string> temp_q;
            for (auto cur: q1) {
                if (q2.count(cur) > 0)
                    return step;
                visited.insert(cur);
                for (int j = 0; j < 4; j++) {
                    char ch = cur[j];
                    // 向上翻滚
                    cur[j] = ch == '9' ? '0' : ch + 1;
                    if (visited.count(cur) == 0) {
                        temp_q.insert(cur);
                    }
                    // 向下翻滚
                    cur[j] = ch == '0' ? '9' : ch - 1;
                    if (visited.count(cur) == 0) {
                        temp_q.insert(cur);
                    }
                    cur[j] = ch;
                }
            }
            step++;
            q1 = q2;
            q2 = temp_q;
        }
        return -1;
    }
};

int main() {
    SolutionV3 s;
    std::vector<std::string> deadends = {"0201", "0101", "0102", "1212", "2002"};
    std::string target = "0202";
    std::cout << s.openLock(deadends, target) << std::endl;
    deadends = {"8887","8889","8878","8898","8788","8988","7888","9888"};
    target = "8888";
    std::cout << s.openLock(deadends, target) << std::endl;
    return 0;
}
