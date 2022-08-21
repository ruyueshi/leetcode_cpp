/**
 * JZ13. 机器人的运动范围
 * Source: https://www.nowcoder.com/practice/6e5207314b5241fb83f2329e89fdecc8?tpId=13&tqId=23460&ru=/exam/oj/ta&qru=/ta/coding-interviews/question-ranking&sourceUrl=%2Fexam%2Foj%2Fta%3Fpage%3D1%26tpId%3D13%26type%3D13
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int movingCount(int threshold, int rows, int cols) {
        int count = 0;
        int i_bits_sum = 8;
        std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols, false));
        for (int i = 0; i < rows; i++) {
            if (i % 10 == 0) {
                i_bits_sum = i_bits_sum - 9 + 1;
            } else {
                i_bits_sum++;
            }
            if (i_bits_sum > threshold) {
                break;
            }
            int j_bits_sum = 8;
            for (int j = 0; j < cols; j++) {
                if (j % 10 == 0) {
                    j_bits_sum = j_bits_sum - 9 + 1;
                } else {
                    j_bits_sum++;
                }
                if (i_bits_sum + j_bits_sum > threshold) {
                    continue;
                }
                if ((j == 0 || j > 0 && visited[i][j-1]) || (i > 0 && visited[i - 1][j])) {
                    count++;
                    visited[i][j] = true;
                }
            }
        }
        return count;
    }
};

int main() {
    Solution s;
    std::cout << s.movingCount(1, 2, 3) << std::endl;
    std::cout << s.movingCount(10, 1, 100) << std::endl;
    std::cout << s.movingCount(5, 10, 15) << std::endl;
    std::cout << s.movingCount(15, 20, 20) << std::endl;
    return 0;
}
