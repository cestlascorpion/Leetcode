//
// Created by Wang on 2019/12/2.
//

#include "Leetcode671cn.h"

int Leetcode671cn::findSecondMinimumValue(TreeNode *root) { return helper(root, root->val); }

int Leetcode671cn::helper(TreeNode *node, int min) {
    if (node->left == nullptr && node->right == nullptr) {
        return -1;
    }
    int left = node->left->val == min ? helper(node->left, min) : node->left->val;
    int right = node->right->val == min ? helper(node->right, min) : node->right->val;

    if (left == -1)
        return right;
    if (right == -1)
        return left;
    if (left > min && left <= right)
        return left;

    if (right > min && right <= left) {
        return right;
    }
    return -1;
}
