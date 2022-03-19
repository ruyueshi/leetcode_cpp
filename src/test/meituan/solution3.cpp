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
