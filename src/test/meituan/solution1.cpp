#include <algorithm>
#include <iostream>

int get_m(int *nums, int n, int x, int y) {
    std::sort(nums, nums + n);
    int i = 0;
    while (i < n) {
        int dummy_m = nums[i] - 1, good = n - i, bad = i - 0;
        if (good >= x && good <= y && bad >= x && bad <= y)
            return dummy_m;
        i++;
        while (i < n && nums[i] == nums[i-1])
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