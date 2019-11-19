//
// Created by Wang on 2019/11/21.
//

#include "Leetcode285cn.h"

TreeNode *Leetcode285cn::inorderSuccessor(TreeNode *root, TreeNode *p) {
    if (root == nullptr || p == nullptr) return nullptr;

    auto *node = p->right;
    while (node && node->left) {
        node = node->left;
    }
    if (node != nullptr) {
        return node;
    }

    auto *cursor = root;
    stack<TreeNode *> path;
    while (cursor != nullptr) {
        if (cursor->val == p->val) {
            break;
        }
        path.push(cursor);
        if (cursor->val < p->val) {
            cursor = cursor->right;
        } else {
            cursor = cursor->left;
        }
    }
    while (!path.empty()) {
        if (path.top()->left && path.top()->left->val == p->val) {
            return path.top();
        }
        p = path.top();
        path.pop();
    }
    return nullptr;
}