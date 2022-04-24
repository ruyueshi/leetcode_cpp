/*
链接：https://www.nowcoder.com/question/next?pid=38431372&qid=2501690&tid=55738913
来源：牛客网
给定一个n*n的地图。地图是上下左右四联通的，不能斜向行走：
*代表障碍，不可通行。
.代表路，可以通行。
#代表房子。房子也是可以通行的。

小红现在需要在一些地方安排一些超市（不能安排在障碍物上，可以安排在路上或者房子上。超市也是可以通行的）。
小红希望每个房子至少可以到达一个超市。同时由于成本原因，小红希望超市的数量尽可能少。
在超市数量最少的情况下，小红希望每个房子到达最近的超市的距离之和尽可能小。
她想知道超市最少的数量，以及最小的距离之和。你能帮帮她吗？

输入描述:
第一行一个正整数n，代表地图的大小。( 1&lt;=n&lt;=50 )<br>接下来的n行，每行一个长度为n的字符串，表示整个地图。保证输入合法。<br>

输出描述:
输出两个整数，用空格隔开。分别代表超市的最小数量、最小的距离之和。

输入例子1:
3
#.#
.**
*.#

输出例子1:
2 2

例子说明1:
下标从1开始，第一个超市安排的位置是(1,2)，第二个超市安排的位置是(3,3)。三个房子到超市的距离分别为1,1,0。

输入例子2:
3
#*#
.**
*.#

输出例子2:
3 0

例子说明2:
分别在三个房子上建3个超市即可。

输入例子3:
2
.*
*.

输出例子3:
0 0

例子说明3:
没有房子，所以不用造超市
 */

#include <iostream>
#include <queue>

int n;
std::vector<std::string> m;
int direction[4][2] = {{-1, 0},
                       {1,  0},
                       {0,  -1},
                       {0,  1}};
bool flag;  // 当前区域是否有房子

// 深度优先搜索当前区域是否有房子，并记录区域中的所有坐标
void dfs(std::vector<std::pair<int, int>> &area, std::vector<std::vector<bool>> &visited, int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= n || m[i][j] == '*' || visited[i][j])
        return;
    visited[i][j] = true;
    area.emplace_back(i, j);
    if (!flag && m[i][j] == '#')
        flag = true;
    for (const auto &d: direction) {
        dfs(area, visited, i + d[0], j + d[1]);
    }
}

// 以当前区域的每一个点为超市进行广度优先搜索，取路径和最小的点为超市，并返回其路径和
int bfs(const std::vector<std::pair<int, int>> &area) {
    int area_path = INT32_MAX;
    for (const auto &point: area) {
        int path = 0;
        int step = 0;
        std::queue<std::pair<int, int>> q;
        q.push(point);
        std::vector<std::vector<bool>> visited(n, std::vector<bool>(n));
        visited[point.first][point.second] = true;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto p = q.front();
                q.pop();
                if (m[p.first][p.second] == '#') {
                    path += step;
                }
                for (const auto &d: direction) {
                    int ii = p.first + d[0], jj = p.second + d[1];
                    if (ii < 0 || ii >= n || jj < 0 || jj >= n || m[ii][jj] == '*' || visited[ii][jj])
                        continue;
                    q.push({ii, jj});
                    visited[ii][jj] = true;
                }
            }
            step++;
        }
        area_path = std::min(area_path, path);
    }
    return area_path;
}

int main() {
    std::cin >> n;
    m.resize(n);
    for (int i = 0; i < n; i++) {
        std::cin >> m[i];
    }

    std::vector<std::vector<bool>> visited(n, std::vector<bool>(n));

    int market_num = 0, total_path = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (m[i][j] == '*' || visited[i][j])
                continue;
            std::vector<std::pair<int, int>> area;
            flag = false;
            dfs(area, visited, i, j);
            if (!flag)  // flag=false说明当前区域没有房子
                continue;
            market_num++;
            total_path += bfs(area);
        }
    }

    std::cout << market_num << " " << total_path << std::endl;
    return 0;
}
