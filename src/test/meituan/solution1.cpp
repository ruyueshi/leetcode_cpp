/*
链接：https://www.nowcoder.com/questionTerminal/9c4a4e879b4f49939dfaebea8948f976
来源：牛客网
某比赛已经进入了淘汰赛阶段,已知共有n名选手参与了此阶段比赛，他们的得分分别是a_1,a_2….a_n,小美作为比赛的裁判希望设定一个分数线m，使得所有分数大于m的选手晋级，其他人淘汰。
但是为了保护粉丝脆弱的心脏，小美希望晋级和淘汰的人数均在[x,y]之间。
显然这个m有可能是不存在的，也有可能存在多个m，如果不存在，请你输出-1，如果存在多个，请你输出符合条件的最低的分数线。
数据范围：1\le n \le 50000\1≤n≤50000 ，1 \le x \le y \le n\1≤x≤y≤n
进阶：时间复杂度O(nlogn)\O(nlogn) ，空间复杂度O(n)\O(n)

输入描述:
输入第一行仅包含三个正整数n,x,y，分别表示参赛的人数和晋级淘汰人数区间。(1<=n<=50000,1<=x,y<=n)
输入第二行包含n个整数，中间用空格隔开，表示从1号选手到n号选手的成绩。(1<=|a_i|<=1000)

输出描述:
输出仅包含一个整数，如果不存在这样的m，则输出-1，否则输出符合条件的最小的值。

示例1
输入
6 2 3
1 2 3 4 5 6
输出
3
 */

#include <algorithm>
#include <iostream>

int get_m(int *nums, int n, int x, int y) {
    std::sort(nums, nums + n);
    int i = x - 1;
    while (i <= y - 1) {
        while (i <= y - 2 && nums[i + 1] == nums[i])
            i++;
        int dummy_m = nums[i];
        int good = (n - 1) - i, bad = i - 0 + 1;
        if (good >= x && good <= y && bad >= x && bad <= y)
            return dummy_m;
        i++;
    }
    return -1;
}

int main() {
    int n, x, y;
    std::cin >> n >> x >> y;
    int nums[n];
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }
    std::cout << get_m(nums, n, x, y) << std::endl;
    return 0;
}