/*
链接：https://www.nowcoder.com/test/question/42852fd7045c442192fa89404ab42e92?pid=16516564&tid=56064847
来源：牛客网
我叫王大锤，是一名特工。我刚刚接到任务：在字节跳动大街进行埋伏，抓捕恐怖分子孔连顺。和我一起行动的还有另外两名特工，我提议

1. 我们在字节跳动大街的 N 个建筑中选定 3 个埋伏地点。
2. 为了相互照应，我们决定相距最远的两名特工间的距离不超过 D 。

我特喵是个天才! 经过精密的计算，我们从X种可行的埋伏方案中选择了一种。这个方案万无一失，颤抖吧，孔连顺！
……
万万没想到，计划还是失败了，孔连顺化妆成小龙女，混在cosplay的队伍中逃出了字节跳动大街。只怪他的伪装太成功了，就是杨过本人来了也发现不了的！

请听题：给定 N（可选作为埋伏点的建筑物数）、 D（相距最远的两名特工间的距离的最大值）以及可选建筑的坐标，计算在这次行动中，大锤的小队有多少种埋伏选择。
注意：
1. 两个特工不能埋伏在同一地点
2. 三个特工是等价的：即同样的位置组合( A , B , C ) 只算一种埋伏方法，不能因“特工之间互换位置”而重复使用


数据范围：

输入描述:
第一行包含空格分隔的两个数字 N和D(1 ≤ N ≤ 1000000; 1 ≤ D ≤ 1000000)

第二行包含N个建筑物的的位置，每个位置用一个整数（取值区间为[0, 1000000]）表示，从小到大排列（将字节跳动大街看做一条数轴）

输出描述:
一个数字，表示不同埋伏方案的数量。结果可能溢出，请对 99997867 取模

输入例子1:
4 3
1 2 3 4

输出例子1:
4

例子说明1:
可选方案 (1, 2, 3), (1, 2, 4), (1, 3, 4), (2, 3, 4)

输入例子2:
5 19
1 10 20 30 50

输出例子2:
1

例子说明2:
可选方案 (1, 10, 20)

输入例子3:
2 100
1 102

输出例子3:
0

例子说明3:
无可选方案
 */

#include <iostream>
#include <vector>

int N, D;

// 超时
int get_strategies_v1(std::vector<int> &position) {
    if (N < 3 || D < 2)
        return 0;
    int res = 0;
    for (int i = 0; i < N - 2; i++) {
        for (int j = i + 1; j < N - 1; j++) {
            if (position[j] - position[i] > D)
                break;
            for (int k = j + 1; k < N; k++) {
                if (position[k] - position[i] > D || position[k] - position[j] > D)
                    break;
                res = (res + 1) % 99997867;
            }
        }
    }
    return res;
}

int get_strategies_v2(std::vector<int> &position) {
    if (N < 3 || D < 2)
        return 0;
    long long res = 0;
    int left = 0;
    int right = 0;
    while (left < N - 2) {
        while (right < N && position[right] - position[left] <= D)
            right++;
        if (right - 1 - left >= 2) {
            long long num = right - 1 - left;
            res = (res + (num * (num - 1) / 2) % 99997867) % 99997867;
        }
        left++;
    }
    return res;
}

int main() {
    std::cin >> N >> D;
    std::vector<int> position(N);
    for (int i = 0; i < N; i++) {
        std::cin >> position[i];
    }
    std::cout << get_strategies_v2(position) << std::endl;
    return 0;
}
