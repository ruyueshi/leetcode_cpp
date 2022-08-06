/**
 * JZ32. 从上往下打印二叉树
 * Source: https://www.nowcoder.com/practice/7fe2212963db4790b57431d9ed259701?tpId=13&tqId=23280&ru=/exam/oj/ta&qru=/ta/coding-interviews/question-ranking&sourceUrl=%2Fexam%2Foj%2Fta%3Fpage%3D1%26tpId%3D13%26type%3D13
 */

#include "src/utils/tree.h"
#include "src/utils/print.h"

using namespace std;

class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if (sequence.size() == 0)
            return false;
        return is_possible_postorder(sequence, 0, sequence.size() - 1);
    }

private:
    bool is_possible_postorder(const std::vector<int> &sequence, int start, int end) {
        if (start >= end) {
            return true;
        }
        int current_root = sequence[end];
        int first_seg = start;
        while (first_seg < end && sequence[first_seg] < current_root) {
            first_seg++;
        }
        if (first_seg == end) {
            return is_possible_postorder(sequence, start, first_seg - 1);
        }
        int second_seg = first_seg;
        while (second_seg < end && sequence[second_seg] > current_root) {
            second_seg++;
        }
        if (second_seg < end) {
            return false;
        } else {
            return is_possible_postorder(sequence, start, first_seg - 1) &&
                   is_possible_postorder(sequence, first_seg, second_seg - 1);
        }
    }
};

int main() {
    Solution s;
    std::cout << s.VerifySquenceOfBST({5, 7, 6, 9, 11, 10, 8}) << std::endl;
    return 0;
}
