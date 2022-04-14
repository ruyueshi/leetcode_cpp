/*
链接：https://www.nowcoder.com/question/next?pid=21499819&qid=846170&tid=55268698
来源：牛客网
一台新机器，第4年可以生产一台机器，以后每一年生产1台。 生产出来的新机器第4年又可以生产一台机器，后续每年可以生产1台。
现在有一台新机器，求第n年总共有多少台机器。 计算结果对109+7取模。

输入描述:
输入一个数字 n，表示计算第 n 年总共有多少台机器。（1<=n<=106）

输出描述:
输出第 n 年总共的机器的台数 X 对109+7取模之后的结果。

输入例子1:
10

输出例子1:
19

输入例子2:
15

输出例子2:
129
 */

#include <iostream>


int main() {
    int n;
    std::cin >> n;
    int new_machine[3] = {1, 0, 0};  // 机器年龄小于4年的新机器
    int old_machine = 0;  // 机器年龄大于等于4年的老机器
    int mod = 1e9 + 7;
    for (int i = 2; i <= n; i++) {
        old_machine = (old_machine + new_machine[2]) % mod;
        new_machine[2] = new_machine[1];
        new_machine[1] = new_machine[0];
        new_machine[0] = old_machine;
    }
    int sum = 0;
    for (int i = 0; i < 3; i++)
        sum = (sum + new_machine[i]) % mod;
    sum = (sum + old_machine) % mod;
    std::cout << sum << std::endl;
    return 0;
}