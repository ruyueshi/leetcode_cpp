/*
链接：https://www.nowcoder.com/question/next?pid=21499819&qid=845958&tid=55268698
来源：牛客网
把m个同样的足球放进n个同样的篮子里，允许有的篮子为空，问共有几种分法？
例如：3, 2, 1和2, 1, 3是同一种分法。

输入描述:
一行两个数字n，m（1<=n<=70，1<=m<=70）用空格隔开，表示篮子数和足球数。

输出描述:
一个整数 x 表示不同的分法数。

输入例子1:
3 7

输出例子1:
8
 */

#include <iostream>

int traceback(int m, int n, int start) {
    if (n <= 1)
        return n;
    if (m <= 1)
        return 1;
    int count = 0;
    for (int i = start; i < m; i++) {
        if (m - i < i / double(n - 1))
            break;
        count += traceback(i, n - 1, std::max(0, i - (m - i)));
    }
    return count;
}


int main() {
    int m, n;
    std::cin >> n >> m;
    std::cout << traceback(m, n, 0) << std::endl;
    return 0;
}