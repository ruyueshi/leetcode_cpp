/*
链接：https://www.nowcoder.com/questionTerminal/0d6a89336a0147eb8785aee5af21cb42?f=discussion
来源：牛客网

小A在玩一个网络游戏。这个游戏有个抽装备环节。装备池总共有n+m件装备，分别为n件普通装备和m件ssr装备。抽一次装备的费用按你抽中的装备决定。

抽中每一件装备的概率都为1/(n+m)。如果你抽中了ssr装备。这次的抽装备费用为2金币，否则这次的费用为1金币。如果你抽中了ssr装备，得到奖励，并且装备不会放回。如果你抽中了普通装备。得到奖励，但是这件装备会放回装备池。现在小A希望抽中所有的ssr装备，请你计算一下：需要花费金币的期望值。


输入描述:
输入一行：n,m(1<=n,m<=106)


输出描述:
抽中所有的ssr装备，需要花费金币的期望值。输出保留2位有效小数。
示例1
输入
2 1
输出
4.00
示例2
输入
2 2
输出
7.00
示例3
输入
5 6
输出
24.25
 */


#include<iostream>
#include <iomanip>

using namespace std;

int main() {
    int n, m;
    while (cin >> n) {
        cin >> m;
        double val = 0.00;
        for (int i = 1; i <= m; ++i) {
            val = val + 2 + (double) n / i;
        }
        cout << fixed << setprecision(2) << val << endl;
    }
}
