#include <algorithm>
#include <iostream>

int get_regular_sequence(int *nums, int n) {
    std::sort(nums, nums + n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += std::abs(i + 1 - nums[i]);
    }
    return sum;
}

int main() {
    int n;
    std::cin >> n;
    int nums[n];
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }
    std::cout << get_regular_sequence(nums, n) << std::endl;
    return 0;
}