/*
链接：https://www.nowcoder.com/test/question/fe298c55694f4ed39e256170ff2c205f?pid=1088888&tid=55165516
来源：牛客网
某商店规定：三个空汽水瓶可以换一瓶汽水，允许向老板借空汽水瓶（但是必须要归还）。
小张手上有n个空汽水瓶，她想知道自己最多可以喝到多少瓶汽水。
数据范围：输入的正整数满足

注意：本题存在多组输入。输入的 0 表示输入结束，并不用输出结果。

输入描述:
输入文件最多包含 10 组测试数据，每个数据占一行，仅包含一个正整数 n（ 1<=n<=100 ），表示小张手上的空汽水瓶数。n=0 表示输入结束，你的程序不应当处理这一行。


输出描述:
对于每组测试数据，输出一行，表示最多可以喝的汽水瓶数。如果一瓶也喝不到，输出0。


输入例子1:
3
10
81
0

输出例子1:
1
5
40

例子说明1:
样例 1 解释：用三个空瓶换一瓶汽水，剩一个空瓶无法继续交换
样例 2 解释：用九个空瓶换三瓶汽水，剩四个空瓶再用三个空瓶换一瓶汽水，剩两个空瓶，向老板借一个空瓶再用三个空瓶换一瓶汽水喝完得一个空瓶还给老板
 */

#include <iostream>

int water_bottle(int n) {
    int sum = 0;
    while (n > 1) {
        if (n == 2) {
            sum += 1;
            break;
        } else {
            sum += (n / 3);
            n = n / 3 + n % 3;
        }
    }
    return sum;
}

int main() {
    int n;
    while (1) {
        std::cin >> n;
        if (n == 0)
            break;
        std::cout << water_bottle(n) << std::endl;
    }
    return 0;
}