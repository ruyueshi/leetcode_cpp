/**
 * JZ27. 二叉树的镜像
 * Source: https://www.nowcoder.com/practice/a9d0ecbacef9410ca97463e4a5c83be7?tpId=13&tqId=1374963&ru=/exam/oj/ta&qru=/ta/coding-interviews/question-ranking&sourceUrl=%2Fexam%2Foj%2Fta%3Fpage%3D1%26tpId%3D13%26type%3D13
 */

#include "src/utils/tree.h"

using namespace std;

class Solution {
public:
    TreeNode* Mirror(TreeNode* pRoot) {
        // write code here
        if (!pRoot) {
            return nullptr;
        }
        auto temp  = Mirror(pRoot->left);
        pRoot->left = Mirror(pRoot->right);
        pRoot->right =  temp;
        return pRoot;
    }
};

int main() {
    Solution s;
    print_tree1(s.Mirror(construct_tree({8,6,10,5,7,9,11})));
    return 0;
}
