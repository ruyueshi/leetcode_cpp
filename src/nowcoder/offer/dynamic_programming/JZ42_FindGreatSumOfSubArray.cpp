/**
 * JZ42. 连续子数组的最大和
 * Source: https://www.nowcoder.com/practice/459bd355da1549fa8a49e350bf3df484?tpId=13&tqId=23259&ru=/exam/oj/ta&qru=/ta/coding-interviews/question-ranking&sourceUrl=%2Fexam%2Foj%2Fta%3Fpage%3D1%26tpId%3D13%26type%3D13
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int n = array.size();
        int dp = array[0];
        int sum = array[0];
        for (int i = 1; i < n; i++) {
            if (dp >= 0) {
                dp = dp + array[i];
            } else {
                dp = array[i];
            }
            sum = std::max(sum, dp);
        }
        return sum;
    }
};

int main() {
    Solution s;
    std::cout << s.FindGreatestSumOfSubArray({1,-2,3,10,-4,7,2,-5}) << std::endl;
    return 0;
}