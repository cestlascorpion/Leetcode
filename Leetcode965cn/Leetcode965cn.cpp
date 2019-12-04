//
// Created by Wang on 2019/12/4.
//

#include "Leetcode965cn.h"

bool Leetcode965cn::isUnivalTree(TreeNode *root) {
    if (root == nullptr) {
        return true;
    }

    return check(root, root->val);
}

bool Leetcode965cn::check(TreeNode *node, int val) {
    if (node->val != val)
        return false;

    bool l = node->left == nullptr ? true : check(node->left, val);
    if (!l)
        return false;

    bool r = node->right == nullptr ? true : check(node->right, val);
    if (!r)
        return false;

    return true;
}
