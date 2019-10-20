//
// Created by Wang on 2019/10/20.
//

#include "Leetcode235cn.h"

TreeNode *Leetcode235cn::lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    TreeNode *left;
    TreeNode *right;
    if (p->val < q->val) {
        left = p;
        right = q;
    } else {
        left = q;
        right = p;
    }

    TreeNode *ancestor = root;
    while (ancestor != nullptr) {
        if (left == ancestor || right == ancestor) {
            return ancestor;
        }
        if (left->val > ancestor->val) {
            ancestor = ancestor->right;
        } else if (right->val < ancestor->val) {
            ancestor = ancestor->left;
        } else {
            return ancestor;
        }
    }
    return nullptr;
}
