/**
 * JZ41. 数据流中的中位数
 * Source: https://www.nowcoder.com/practice/9be0172896bd43948f8a32fb954e1be1?tpId=13&tqId=23457&ru=/exam/oj/ta&qru=/ta/coding-interviews/question-ranking&sourceUrl=%2Fexam%2Foj%2Fta%3Fpage%3D1%26tpId%3D13%26type%3D13
 */

#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    void Insert(int num) {
        if (vec.empty()) {
            vec.push_back(num);
        } else {
            auto it = std::lower_bound(vec.begin(), vec.end(), num);
            vec.insert(it, num);
        }
    }

    double GetMedian() {
        int size = vec.size();
        if (size % 2 == 1) {
            return static_cast<double>(vec[size / 2]);
        } else {
            return static_cast<double>(vec[size/2-1] + vec[size/2]) / 2;
        }
    }

private:
    std::vector<int> vec;
};

int main() {
    Solution s;
    std::vector<int> nums = {5,2,3,4,1,6,7,0,8};
    for (int num : nums) {
        s.Insert(num);
        std::cout << s.GetMedian() << ",";
    }
    std::cout << std::endl;
    return 0;
}
