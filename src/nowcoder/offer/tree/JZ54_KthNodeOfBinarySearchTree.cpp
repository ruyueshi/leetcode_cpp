/**
 * JZ54. 二叉搜索树的第K个节点
 * Source: https://www.nowcoder.com/practice/57aa0bab91884a10b5136ca2c087f8ff?tpId=13&tqId=2305268&ru=/exam/oj/ta&qru=/ta/coding-interviews/question-ranking&sourceUrl=%2Fexam%2Foj%2Fta%3Fpage%3D1%26tpId%3D13%26type%3D13
 */

#include "src/utils/tree.h"


class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param proot TreeNode类
     * @param k int整型
     * @return int整型
     */
    int KthNode(TreeNode* proot, int k) {
        // write code here
        if (!proot || k == 0) {
            return -1;
        }
        res = -1;
        int num = 0;
        traverse(proot, k, num);
        return res;
    }

private:
    int res;
    int traverse(const TreeNode* proot, const int k, int &num) {
        if (!proot) {
            return -1;
        }
        int left = traverse(proot->left, k, num);
        if (left >= 0) {
            return left;
        } else if (++num == k) {
            res = proot->val;
            return res;
        }
        int right = traverse(proot->right, k, num);
        if (right >= 0) {
            return right;
        }
        return -1;
    }
};

int main() {
    std::cout << Solution().KthNode(construct_tree({1}), 0) << std::endl;
    std::cout << Solution().KthNode(construct_tree({5,3,7,2,4,6,8}), 3) << std::endl;
    return 0;
}
