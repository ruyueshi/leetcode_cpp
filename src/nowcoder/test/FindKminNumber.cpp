#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

std::vector<int> FindKminNumber(std::vector<int> arr, int n) {
    std::sort(arr.begin(), arr.end());
    std::vector<int> res;
    res.assign(arr.begin(), arr.begin() + n);
    return res;
}

int main() {
    std::vector<int> arr;
    int num;
    while (std::cin >> num) {
        arr.push_back(num);
        if (std::cin.get() == '\n')
            break;
    }
    int n;
    std::cin >> n;
    auto res = FindKminNumber(arr, n);
    for (int re : res) {
        std::cout << re << ",";
    }
    if (!res.empty())
        std::cout << "\b\n";
    return 0;
}
