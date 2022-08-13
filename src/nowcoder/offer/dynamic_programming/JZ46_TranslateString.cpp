/**
 * JZ46 把数字翻译成字符串
 * Source: https://www.nowcoder.com/practice/046a55e6cd274cffb88fc32dba695668?tpId=13&tqId=1024831&ru=/exam/oj/ta&qru=/ta/coding-interviews/question-ranking&sourceUrl=%2Fexam%2Foj%2Fta%3Fpage%3D1%26tpId%3D13%26type%3D13
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class SolutionV1 {
public:
    /**
     * 解码
     * @param nums string字符串 数字串
     * @return int整型
     */
    int solve(string nums) {
        // write code here
        int n = nums.length();
        int dp[n + 1];
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            int two_bits = std::atoi(nums.substr(i - 2, 2).c_str());
            if (two_bits >= 11 && two_bits <= 26 && two_bits != 20) {
                dp[i] = dp[i - 1] + dp[i - 2];
            } else if (two_bits % 10 == 0 && two_bits > 26) {
                return 0;
            } else {
                dp[i] = dp[i - 1];
            }
        }
        return dp[n];
    }
};

class SolutionV2 {
public:
    /**
     * 解码
     * @param nums string字符串 数字串
     * @return int整型
     */
    int solve(string nums) {
        // write code here
        int n = nums.length();
        int dp_i = 1, dp_i_1 = 1,  temp;
        for (int i = 2; i <= n; i++) {
            int two_bits = std::atoi(nums.substr(i - 2, 2).c_str());
            if (two_bits >= 11 && two_bits <= 26 && two_bits != 20) {
                temp  = dp_i;
                dp_i = dp_i + dp_i_1;
                dp_i_1 = temp;
            } else if (two_bits % 10 == 0 && two_bits > 26) {
                return 0;
            } else {
                dp_i_1 = dp_i;
            }
        }
        return dp_i;
    }
};

int main() {
    SolutionV2 s;
    std::cout << s.solve("12") << std::endl;
    std::cout << s.solve("31717126241541717") << std::endl;
    return 0;
}
