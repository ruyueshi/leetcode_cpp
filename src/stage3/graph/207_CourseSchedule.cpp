/**
 * 207. Course Schedule
 * Source: https://leetcode-cn.com/problems/course-schedule/
 */

#include <iostream>
#include <forward_list>
#include <vector>

class Solution {
public:
    bool canFinish(int numCourses, std::vector<std::vector<int>> &prerequisites) {
        std::vector<std::forward_list<int>> graph(numCourses);
        for (auto &p: prerequisites) {
            graph[p[0]].push_front(p[1]);
        }
        std::vector<bool> visited(numCourses, false), path(numCourses, false);
        for (int i = 0; i < numCourses; i++)
            traceback(graph, visited, path, i);
        return !has_cycle;
    }

private:
    bool has_cycle = false;

    void traceback(const std::vector<std::forward_list<int>> &graph, std::vector<bool> &visited, std::vector<bool> &path, int s) {
        if (path[s]) {
            has_cycle = true;
        }
        if (visited[s] || has_cycle)
            return;

        visited[s] = true;
        path[s] = true;
        for (int t: graph[s]) {
            traceback(graph, visited, path, t);
        }
        path[s] = false;
    }
};

int main() {
    Solution s;
    std::vector<std::vector<int>> prerequisites = {{0, 1},
                                                   {1, 0}};
    std::cout << s.canFinish(2, prerequisites) << std::endl;
    return 0;
}
