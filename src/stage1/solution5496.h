/**
 * 5496. 你可以获得的最大硬币数目
 * Source: https://leetcode-cn.com/contest/weekly-contest-203/problems/maximum-number-of-coins-you-can-get/
 */

#ifndef SOLUTION5496_H
#define SOLUTION5496_H

#include <iostream>
#include <vector>
#include <algorithm>

class solution5496 {
public:
    int maxCoins(std::vector<int>& piles) {
        std::sort(piles.begin(), piles.end());
        int sum = 0;
        int size = piles.size();
        for (int i = size - 2; i >= size / 3; i -= 2) {
            sum += piles[i];
        }
        return sum;
    }
};

static void test_solution5496() {
    solution5496 s;
    std::vector<int> piles = {9,8,7,6,5,1,2,3,4};
    std::cout << s.maxCoins(piles) << std::endl;
}

#endif // SOLUTION5496_H
