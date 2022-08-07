/**
 * JZ85. 连续子数组的最大和（二）
 * Source: https://www.nowcoder.com/practice/11662ff51a714bbd8de809a89c481e21?tpId=13&tqId=2282583&ru=/exam/oj/ta&qru=/ta/coding-interviews/question-ranking&sourceUrl=%2Fexam%2Foj%2Fta%3Fpage%3D1%26tpId%3D13%26type%3D13
 */

#include "src/utils/print.h"

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> FindGreatestSumOfSubArray(vector<int> array) {
        int n = array.size();
        int dp = array[0];
        int sum = array[0];
        int start = 0, end = 0;
        int max_start = 0, max_end = 0;
        for (int i = 1; i < n; i++) {
            if (dp >= 0) {
                dp = dp + array[i];
                end = i;
            } else {
                dp = array[i];
                start = end = i;
            }
            if (dp >= sum) {
                sum = dp;
                max_start = start, max_end = end;
            }
        }
        std::vector<int> res(max_end - max_start + 1);
        res.assign(array.begin() + max_start, array.begin() + max_end + 1);
        return res;
    }
};

int main() {
    Solution s;
    print_vector(s.FindGreatestSumOfSubArray({1,2,-3,4,-1,1,-3,2}));
    return 0;
}