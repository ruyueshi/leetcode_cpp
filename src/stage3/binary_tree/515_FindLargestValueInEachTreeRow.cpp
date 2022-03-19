/**
 * 515. Find Largest Value in Each Tree Row
 * Source: https://leetcode-cn.com/problems/find-largest-value-in-each-tree-row/
 */

#include <queue>
#include <vector>

#include "src/utils/print.h"
#include "src/utils/tree.h"

class Solution {
public:
    std::vector<int> largestValues(TreeNode *root) {
        std::queue<TreeNode *> q;
        std::vector<int> res;
        if (root)
            q.push(root);
        while (!q.empty()) {
            int cur_max = INT_MIN;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto p = q.front();
                q.pop();
                cur_max = std::max(cur_max, p->val);
                if (p->left)
                    q.push(p->left);
                if (p->right)
                    q.push(p->right);
            }
            res.push_back(cur_max);
        }
        return res;
    }
};

int main() {
    Solution s;
    print_vector(s.largestValues(construct_tree({1, 3, 2, 5, 3, INT_MIN, 9})));
    print_vector(s.largestValues(construct_tree({1, 2, 3})));
    return 0;
}
