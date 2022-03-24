/**
 * 210. Course Schedule II
 * Source: https://leetcode-cn.com/problems/course-schedule-ii/
 */

#include <algorithm>
#include <vector>

#include "src/utils/print.h"

class Solution {
public:
    std::vector<int> findOrder(int numCourses, std::vector<std::vector<int>> &prerequisites) {
        std::vector<std::vector<int>> graph(numCourses);
        // build graph
        for (auto &p: prerequisites)
            graph[p[0]].push_back(p[1]);  // 现在是依赖方指向被依赖方，颠倒方向后可以不用堆后续遍历进行反转

        std::vector<bool> visited(numCourses, false), path(numCourses, false);

        for (int s = 0; s < numCourses; s++)
            traceback(graph, visited, path, s);

        if (has_cycle)
            return {};

        // std::reverse(res.begin(), res.end());
        return res;
    }

private:
    bool has_cycle = false;
    std::vector<int> res;

    void traceback(const std::vector<std::vector<int>> &graph, std::vector<bool> &visited, std::vector<bool> &path, int s) {
        if (path[s])
            has_cycle = true;
        if (visited[s] || has_cycle)
            return;

        visited[s] = true;
        path[s] = true;

        for (int t: graph[s])
            traceback(graph, visited, path, t);

        res.push_back(s);
        path[s] = false;
    }
};

int main() {
    Solution s;
    std::vector<std::vector<int>> prerequisites = {{2, 0},
                                                   {1, 0},
                                                   {3, 1},
                                                   {3, 2}};
    print_vector(s.findOrder(4, prerequisites));
    return 0;
}
