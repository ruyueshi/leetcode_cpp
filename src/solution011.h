/*
 * 11. Container With Most Water
 * Source: https://leetcode-cn.com/problems/container-with-most-water/
 */

#ifndef LEETCODE_CPP_SOLUTION011_H
#define LEETCODE_CPP_SOLUTION011_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#include "src/timer.h"


class solution011 {
public:
    // run timeout
    int maxArea1(std::vector<int>& height) {
        int width = height.size() - 1;
        int max = std::min(height.front(), height.back()) * width;
        int shorter_line = std::min(height.front(), height.back());
        do {
            width--;
            int temp_short = shorter_line;
            for (int i = 0; i + width < height.size(); i++) {
                if (height[i] > shorter_line || height[i + width] > shorter_line) {
                    int line = std::min(height[i], height[i + width]);
                    int temp_container = line * width;
                    if (temp_container > max) {
                        max = temp_container;
                        temp_short = line;
                    }
                }
            }
            shorter_line = temp_short;
        } while (width > 1);
        return max;
    }

    // run timeout
    int maxArea2(std::vector<int>& height) {
        int width = height.size() - 1;
        int shorter_line = std::min(height.front(), height.back());
        int max_container = shorter_line * width;
        do {
            width--;
            int current_max_shorter_line = 0;
            for (int i = 0; i + width < height.size(); i++) {
                if (height[i] > shorter_line || height[i + width] > shorter_line > shorter_line) {
                    int temp_min = std::min(height[i], height[i + width]);
                    if (temp_min > current_max_shorter_line) {
                        current_max_shorter_line = temp_min;
                    }
                }
            }
            int temp_max_container = current_max_shorter_line * width;
            if (temp_max_container > max_container) {
                max_container = temp_max_container;
                shorter_line = current_max_shorter_line;
            }
        } while (width > 1);
        return max_container;
    }

    // good
    int maxArea3(std::vector<int> &height) {
        int l = 0, r = height.size() - 1;
        int ans = 0;
        while (l < r) {
            int temp_area = std::min(height[l], height[r]) * (r - l);
            ans = temp_area > ans ? temp_area : ans;
            if (height[l] <= height[r]) {
                l++;
            } else {
                r--;
            }
        }
        return ans;
    }
};

void test_solution011() {
    solution011 s;
    std::vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    std::vector<int> height1;
    for (int i = 15000; i >= 1; i--) {
        height1.push_back(i);
    }

    timer t;
    std::cout << s.maxArea3(height1) << std::endl;
    t.cost();
}

#endif //LEETCODE_CPP_SOLUTION011_H
