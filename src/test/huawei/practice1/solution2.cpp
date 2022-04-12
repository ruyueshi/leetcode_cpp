/*
链接：https://www.nowcoder.com/question/next?pid=1088888&qid=36846&tid=55165516
来源：牛客网
明明生成了N个1到500之间的随机整数。请你删去其中重复的数字，即相同的数字只保留一个，把其余相同的数去掉，然后再把这些数从小到大排序，按照排好的顺序输出。

数据范围：  ，输入的数字大小满足

输入描述:
第一行先输入随机整数的个数 N 。
接下来的 N 行每行输入一个整数，代表明明生成的随机数。
具体格式可以参考下面的"示例"。

输出描述:
输出多行，表示输入数据处理后的结果


输入例子1:
3
2
2
1

输出例子1:
1
2

例子说明1:
输入解释：
第一个数字是3，也即这个小样例的N=3，说明用计算机生成了3个1到500之间的随机整数，接下来每行一个随机数字，共3行，也即这3个随机数字为：
2
2
1
所以样例的输出为：
1
2
 */

#include <iostream>
#include <set>
#include <stack>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *build_tree(const std::vector<int> &nums) {
    auto root = new TreeNode(nums[0]);
    for (int i = 1; i < nums.size(); i++) {
        TreeNode *q = root, *p;
        while (true) {
            p = q;
            if (nums[i] < q->val) {
                q = q->left;
                if (!q) {
                    p->left = new TreeNode(nums[i]);
                    break;
                }
            } else if (nums[i] > q->val) {
                q = q->right;
                if (!q) {
                    q->right = new TreeNode(nums[i]);
                    break;
                }
            } else break;
        }
    }
    return root;
}

void traverse(TreeNode *root) {
    // if (!root)
    //     return;
    // traverse(root->left);
    // std::cout << root->val << std::endl;
    // traverse(root->right);
    std::stack<TreeNode *> s;
    auto p = root;
    while (p || !s.empty()) {
        while (p) {
            s.push(p);
            p = p->left;
        }
        if (!s.empty()) {
            p = s.top();
            s.pop();
            std::cout << p->val << std::endl;
            p = p->right;
        }
    }
}

// V1
int main_v1() {
    int n;
    std::cin >> n;
    std::set<int> nums;
    for (int i = 0; i < n; i++) {
        int num;
        std::cin >> num;
        nums.insert(num);
    }
    for (const auto &num : nums)
        std::cout << num << std::endl;
    return 0;
}

// V2
// 构造二叉搜索树+中序遍历
int main() {
    int n;
    std::cin >> n;
    std::vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }
    auto root = build_tree(nums);
    traverse(root);
    return 0;
}