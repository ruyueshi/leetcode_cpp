/*
链接：https://www.nowcoder.com/test/question/16976852ad2f4e26a1ff9f555234cab2?pid=38431372&tid=55738913
来源：牛客网
给出一个只包含 0 和 1 的 01 串 s ，下标从 1 开始，设第 i 位的价值为 vali ，则价值定义如下：

1. i=1时:val1 = 1
2. i>1时：
2.1 若 si ≠ si-1 , vali = 1
2.2 若 si = si-1 , vali = vali-1 + 1
字符串的价值等于 val1 + val2 + val3 + ... + valn

你可以删除 s 的任意个字符，问这个串的最大价值是多少。

输入描述:
第一行一个正整数 n ，代表串长度。
接下来一行一个 01 串 s 。
1 ≤ n ≤ 5,000

输出描述:
输出一个整数代表答案

输入例子1:
6
010101

输出例子1:
7

例子说明1:
删除后的串为0001或0111时有最大价值

输入例子2:
20
11111000111011101100

输出例子2:
94

输入例子3:
4
1100

输出例子3:
6
 */