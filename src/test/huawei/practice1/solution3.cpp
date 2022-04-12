/*
链接：https://www.nowcoder.com/question/next?pid=1088888&qid=36827&tid=55165516
来源：牛客网
写出一个程序，接受一个十六进制的数，输出该数值的十进制表示。

数据范围：保证结果在

输入描述:
输入一个十六进制的数值字符串。


输出描述:
输出该数值的十进制字符串。不同组的测试用例用\n隔开。


输入例子1:
0xAA

输出例子1:
170
 */

#include <iostream>
#include <cmath>
#include <string>

int main() {
    std::string str;
    std::cin >> str;
    int num = 0;
    int n = str.length();
    for (int i = 2; i < n; i++) {
        if (str[i] >= 'A') {
            num += (str[i] - 'A' + 10) * pow(16, (n - 1 - i));
        } else {
            num += (str[i] - '0') * pow(16, (n - 1 - i));
        }
    }
    std::cout << num << std::endl;
    return 0;
}
