/*
链接：https://www.nowcoder.com/questionTerminal/944e5ca0ea88471fbfa73061ebe95728?answerType=1&f=discussion
来源：牛客网

Z国的货币系统包含面值1元、4元、16元、64元共计4种硬币，以及面值1024元的纸币。现在小Y使用1024元的纸币购买了一件价值为N (0 < N \le 1024)N(0<N≤1024)的商品，请问最少他会收到多少硬币？

输入描述:
一行，包含一个数N。


输出描述:
一行，包含一个数，表示最少收到的硬币数。
示例1
输入
200
输出
17
说明
花200，需要找零824块，找12个64元硬币，3个16元硬币，2个4元硬币即可。

备注:
对于100%的数据，N (0 < N \le 1024)N(0<N≤1024)。
 */

#include <iostream>

int main() {
    int n;
    std::cin >> n;
    n = 1024 - n;
    int coin_num = 0;
    coin_num += n / 64;
    n = n % 64;
    coin_num += n / 16;
    n = n % 16;
    coin_num += n / 4;
    n = n % 4;
    coin_num += n;
    std::cout << coin_num << std::endl;
    return 0;
}
