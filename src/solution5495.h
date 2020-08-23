/**
 * 5495. 圆形赛道上经过次数最多的扇区
 * Source: https://leetcode-cn.com/contest/weekly-contest-203/problems/most-visited-sector-in-a-circular-track/
 */

#ifndef SOLUTION5495_H
#define SOLUTION5495_H

#include <iostream>
#include <vector>
#include <algorithm>

class solution5495 {
public:
    std::vector<int> mostVisited(int n, std::vector<int>& rounds) {
        std::vector<int> nums(n+1, 0);
        nums[rounds[0]] = 1;
        for (size_t i = 1; i < rounds.size(); i++) {
            int j = (rounds[i-1] + 1) % (n + 1) + (rounds[i-1] + 1) / (n + 1);
            int end = rounds[i] % (n + 1) + rounds[i] / (n + 1);
            while (j != end) {
                nums[j]++;
                j = (j + 1) % (n + 1) + (j + 1) / (n + 1);
            };
            nums[j]++;
        }

        std::vector<int> ans;
        int max = nums[1];
        ans.push_back(1);
        for (size_t i = 2; i < nums.size(); i++) {
            if (nums[i] > max) {
                max = nums[i];
                ans.clear();
                ans.push_back(i);
            } else if (nums[i] == max) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};

void test_solution5495() {
    solution5495 s;
    std::vector<int> rounds = {1,3,5,7};
    std::vector<int> ans = s.mostVisited(7, rounds);
    for (auto &a : ans) {
        std::cout << a << ",";
    }
    std::cout << std::endl;
}

#endif // SOLUTION5495_H
