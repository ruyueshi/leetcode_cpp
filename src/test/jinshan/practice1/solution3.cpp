/*
题目描述：
 小明在尝试把一些分子为1的分数（1/x）转化为小数。使用普通计算器的除法功能可以实现，
 但是保留的小数位数非常有限。而小明希望得到n位小数，而且要从小数点后面第d位开始的n位小数。
 例如，x=13, d=4, n=3时，1/13=0.07692307692……，从小数点后第四位开始取三位数，答案是923。
 现在小明想要计算一些数更大的情况（2 <= x <= 10000, 1 <= d <= 1000000000, 1 <= n <= 10000），请你写个程序帮帮他。
 */


#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>

std::string solve_v1(int x, int d, int n) {
    std::string res = "0.";
    int divisor = 10;
    while (res.size() < (2 + d + n - 1)) {
        int diff = divisor / x;
        res += std::to_string(diff);
        divisor = divisor % x * 10;
    }
    return res.substr(2 + d - 1, n);
}

std::string solve_v2(int x, int d, int n) {
    std::string temp_res;  // 记录小数点后的数字
    int divisor = 10;
    std::unordered_map<int, int> m;  // {divisor, index};
    int i = 1;
    while (i <= (d + n - 1)) {
        if (m.count(divisor) > 0) {
            int recurrent_start = m[divisor], recurrent_end = i - 1;
            // std::cout << "come in recurrent: start=" << recurrent_start << ",end=" << recurrent_end << std::endl;
            std::string recurrent = temp_res.substr(recurrent_start - 1, recurrent_end - recurrent_start + 1);
            std::string res;
            if (d < recurrent_start) {
                std::string before_recurrent = temp_res.substr(d - 1, recurrent_start - d);
                if (n > before_recurrent.length()) {
                    int recurrent_num = (n - before_recurrent.length()) / recurrent.length();
                    int last_seg_len = (n - before_recurrent.length()) % recurrent.length();
                    res = before_recurrent;
                    for (int i = 0; i < recurrent_num; i++)
                        res += recurrent;
                    res += recurrent.substr(0, last_seg_len);
                } else {
                    res = before_recurrent.substr(0, n);
                }
            } else {
                int start_in_recurrent = (d - recurrent_start) % recurrent.length();
                std::string first_seg = recurrent.substr(start_in_recurrent);
                if (n > first_seg.length()) {
                    int recurrent_num = (n - first_seg.length()) / recurrent.length();
                    int last_seg_len = (n - first_seg.length()) % recurrent.length();
                    // std::cout << "start_in_recurrent=" << start_in_recurrent << ",recurrent_num=" << recurrent_num << ",first_seg=" << first_seg << std::endl;
                    res = first_seg;
                    for (int i = 0; i < recurrent_num; i++)
                        res += recurrent;
                    res += recurrent.substr(0, last_seg_len);
                } else {
                    res = first_seg.substr(0, n);
                }
            }
            return res;
        }
        int diff = divisor / x;
        m.insert({divisor, i++});
        // std::cout << sizeof(m) << ",";
        temp_res += std::to_string(diff);
        divisor = divisor % x * 10;
    }
    return temp_res.substr(d - 1, n);
}

int main() {
    int x = 13, d = 4, n = 3;

    while (std::cin >> x >> d >> n) {
        // auto res1 = solve_v1(x, d, n);
        // std::cout << res1 << std::endl;
        auto res2 = solve_v2(x, d, n);
        std::cout << res2 << std::endl;
        // std::cout << (res1 == res2) << std::endl;
    }
    return 0;
}