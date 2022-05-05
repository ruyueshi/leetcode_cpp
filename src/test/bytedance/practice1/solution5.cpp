/*
链接：https://www.nowcoder.com/questionTerminal/3d1adf0f16474c90b27a9954b71d125d?answerType=1&f=discussion
来源：牛客网

小明目前在做一份毕业旅行的规划。打算从北京出发，分别去若干个城市，然后再回到北京，每个城市之间均乘坐高铁，且每个城市只去一次。由于经费有限，希望能够通过合理的路线安排尽可能的省一些路上的花销。给定一组城市和每对城市之间的火车票的价钱，找到每个城市只访问一次并返回起点的最小车费花销。

输入描述:
城市个数n（1<n≤20，包括北京）

城市间的车票价钱 n行n列的矩阵 m[n][n]


输出描述:
最小车费花销 s
示例1
输入
4
0 2 6 5
2 0 4 4
6 4 0 2
5 4 2 0
输出
13
说明
共 4 个城市，城市 1 和城市 1 的车费为0，城市 1 和城市 2 之间的车费为 2，城市 1 和城市 3 之间的车费为 6，城市 1 和城市 4 之间的车费为 5，依次类推。假设任意两个城市之间均有单程票可购买，且票价在1000元以内，无需考虑极端情况。
 */

#include <iostream>
#include <vector>

int n;
int price[20][20];
int min_cost = INT32_MAX;

// 超时
void dfs(int city, int i, std::vector<bool> &visited, int sum) {
    if (i == n) {
        min_cost = std::min(min_cost, sum);
        return;
    }

    if (i == n - 1) {
        dfs(0, i + 1, visited, sum + price[city][0]);
        return;
    }

    for (int j = 0; j < n; j++) {
        if (!visited[j]) {
            visited[j] = true;
            dfs(j, i + 1, visited, sum + price[city][j]);
            visited[j] = false;
        }
    }
}

int main() {
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> price[i][j];
        }
    }
    std::vector<bool> visited(n);
    visited[0] = true;
    dfs(0, 0, visited, 0);
    std::cout << min_cost << std::endl;
    return 0;
}
