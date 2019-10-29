//
// Created by Wang on 2019/10/30.
//

#include "Leetcode230cn.h"

int Leetcode230cn::kthSmallest(TreeNode *root, int k) {
    if (root == nullptr || k <= 0) {
        return -1;
    }
    int res = -1;
    stack<TreeNode *> stack;
    TreeNode *p = root;
    while (!stack.empty() || p != nullptr) {
        if (p != nullptr) {
            stack.push(p);
            p = p->left;
        } else {
            p = stack.top();
            --k;
            if (k == 0) {
                res = p->val;
                break;
            }
            stack.pop();
            p = p->right;
        }
    }
    return res;
}
