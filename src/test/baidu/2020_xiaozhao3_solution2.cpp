#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

bool can_live(std::map<int, int> &m, std::vector<int> &a, int &sum, const int &n) {
    if (sum == 0)
        return false;
    std::vector<int> v2, v1;
    for (auto it = m.begin(); it != m.end(); it++) {
        if (it->second == 2) {
            v2.push_back(it->first)
        }
    }
    return false;
}

int main() {
    int T;
    std::cin >> T;
    for (int t = 0; t < T; t++) {
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        std::map<int, int> m;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
            sum += a[i];
            m[a[i]]++;
        }

        bool is_man = true;
        while (sum >= 0) {
            if (!can_live(m, a, sum, n)) {
                std::cout << (is_man ? "man" : "woman") << std::endl;
                break;
            }
            is_man = !is_man;
        }
    }
    return 0;
}
