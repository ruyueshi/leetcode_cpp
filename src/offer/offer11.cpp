/**
 * offer 11. 旋转数组中的最小数字
 * Source: https://leetcode-cn.com/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/
 */

#include <iostream>
#include <vector>

class Solution {
public:
    int minArray(std::vector<int> &numbers) {
        int low = 0, high = numbers.size() - 1;
        while (low < high) {
            int mid = (low + high) / 2;
            if (numbers[mid] > numbers[high])
                low = mid + 1;
            else if (numbers[mid] < numbers[high])
                high = mid;
            else
                high--;
        }
        return numbers[low];
    }
};

int main() {
    Solution s;
    std::vector<int> a = {3, 4, 5, 1, 2};
    std::cout << s.minArray(a) << std::endl;
    return 0;
}
