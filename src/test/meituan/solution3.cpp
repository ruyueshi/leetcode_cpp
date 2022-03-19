/*
链接：https://www.nowcoder.com/questionTerminal/601815bea5544f389bcd20fb5ebca6a8
来源：牛客网
小美和小团所在公司的食堂有N张餐桌，从左到右摆成一排，每张餐桌有2张餐椅供至多2人用餐，公司职员排队进入食堂用餐。小美发现职员用餐的一个规律并告诉小团：当男职员进入食堂时，他会优先选择已经坐有1人的餐桌用餐，只有当每张餐桌要么空着要么坐满2人时，他才会考虑空着的餐桌；
当女职员进入食堂时，她会优先选择未坐人的餐桌用餐，只有当每张餐桌都坐有至少1人时，她才会考虑已经坐有1人的餐桌；
无论男女，当有多张餐桌供职员选择时，他会选择最靠左的餐桌用餐。现在食堂内已有若干人在用餐，另外M个人正排队进入食堂，小团会根据小美告诉他的规律预测排队的每个人分别会坐哪张餐桌。
进阶：时间复杂度O(nlogn)\O(nlogn) ,空间复杂度O(n)\O(n)

输入描述:
第一行输入一个整数T（1<=T<=10），表示数据组数。
每组数据占四行，第一行输入一个整数N（1<=N<=500000）；
第二行输入一个长度为N且仅包含数字0、1、2的字符串，第i个数字表示左起第i张餐桌已坐有的用餐人数；
第三行输入一个整数M（1<=M<=2N且保证排队的每个人进入食堂时都有可供选择的餐桌）；
第四行输入一个长度为M且仅包含字母M、F的字符串，若第i个字母为M，则排在第i的人为男性，否则其为女性。

输出描述:
每组数据输出占M行，第i行输出一个整数j（1<=j<=N），表示排在第i的人将选择左起第j张餐桌用餐。

示例1
输入
1
5
01102
6
MFMMFF
输出
2
1
1
3
4
4
 */

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>

// 超时
// 瓶颈在cin cout
int main1() {
    int T;
    std::cin >> T;
    for (int _ = 0; _ < T; _++) {
        int N, M;
        std::cin >> N;
        char nums[N];
        std::cin >> nums;
        std::cin >> M;
        char retain[M];
        std::cin >> retain;

        std::set<int> s0, s1, s2;
        for (int i = 0; i < N; i++) {
            switch (nums[i]) {
                case '0':
                    s0.insert(i + 1);
                    break;
                case '1':
                    s1.insert(i + 1);
                    break;
                case '2':
                    s2.insert(i + 1);
                    break;
                default:
                    break;
            }
        }

        std::string res;
        for (int i = 0; i < M; i++) {
            if (retain[i] == 'M') {  // 男性
                if (!s1.empty()) {
                    auto it = s1.begin();
                    // std::cout << *it << std::endl;
                    res += std::to_string(*it) + "\n";
                    s2.insert(*it);
                    s1.erase(it);
                } else if (!s0.empty()) {
                    auto it = s0.begin();
                    // std::cout << *it << std::endl;
                    res += std::to_string(*it) + "\n";
                    s1.insert(*it);
                    s0.erase(it);
                }
            } else {
                if (!s0.empty()) {
                    auto it = s0.begin();
                    // std::cout << *it << std::endl;
                    res += std::to_string(*it) + "\n";
                    s1.insert(*it);
                    s0.erase(it);
                } else if (!s1.empty()) {
                    auto it = s1.begin();
                    // std::cout << *it << std::endl;
                    res += std::to_string(*it) + "\n";
                    s2.insert(*it);
                    s1.erase(it);
                }
            }
        }
        std::cout << res;
    }
    return 0;
}

// 可以通过
// 集中输入输出
int main2() {
    int T;
    std::cin >> T;
    int N[T], M[T];
    std::string nums[T], retain[T];

    for (int t = 0; t < T; t++) {
        std::cin >> N[t];
        std::cin >> nums[t];
        std::cin >> M[t];
        std::cin >> retain[t];
    }

    for (int t = 0; t < T; t++) {
        std::set<int> s0, s1, s2;
        for (int i = 0; i < N[t]; i++) {
            switch (nums[t][i]) {
                case '0':
                    s0.insert(i + 1);
                    break;
                case '1':
                    s1.insert(i + 1);
                    break;
                case '2':
                    s2.insert(i + 1);
                    break;
                default:
                    break;
            }
        }

        std::string res;
        for (int i = 0; i < M[t]; i++) {
            if (retain[t][i] == 'M') {  // 男性
                if (!s1.empty()) {
                    auto it = s1.begin();
                    // std::cout << *it << std::endl;
                    res += std::to_string(*it) + "\n";
                    s2.insert(*it);
                    s1.erase(it);
                } else if (!s0.empty()) {
                    auto it = s0.begin();
                    // std::cout << *it << std::endl;
                    res += std::to_string(*it) + "\n";
                    s1.insert(*it);
                    s0.erase(it);
                }
            } else {
                if (!s0.empty()) {
                    auto it = s0.begin();
                    // std::cout << *it << std::endl;
                    res += std::to_string(*it) + "\n";
                    s1.insert(*it);
                    s0.erase(it);
                } else if (!s1.empty()) {
                    auto it = s1.begin();
                    // std::cout << *it << std::endl;
                    res += std::to_string(*it) + "\n";
                    s2.insert(*it);
                    s1.erase(it);
                }
            }
        }
        std::cout << res;
    }
    return 0;
}

int main_test() {
    // std::vector<std::pair<int, char>> m = {{0, '0'},
    //                                        {1, '2'},
    //                                        {2, '1'},
    //                                        {3, '0'},
    //                                        {4, '1'}};
    // std::sort(m.begin(), m.end(), [](std::pair<int, char> t1, std::pair<int, char> t2) { return t1.second < t2.second; });
    // for (auto it = m.begin(); it != m.end(); it++)
    //     std::cout << it->first << ", " << it->second << std::endl;
    // m[0].second = '1';
    // m[4].second = '1';
    // std::sort(m.begin(), m.end(), [](std::pair<int, char> t1, std::pair<int, char> t2) { return t1.second == t2.second ? t1.first < t2.first : t1.second < t2.second; });
    // for (auto it = m.begin(); it != m.end(); it++)
    //     std::cout << it->first << ", " << it->second << std::endl;
    std::map<int, char> m = {{5, '0'},
                             {1, '2'},
                             {6, '1'},
                             {3, '0'},
                             {4, '1'}};
    for (auto &it : m)
        std::cout << it.first << ", " << it.second << std::endl;
    std::set<int> s = {0, 4, 5, 1, 7, 4, 8};
    for (auto it = s.begin(); it != s.end(); it++)
        std::cout << *it << std::endl;
    return 0;
}
