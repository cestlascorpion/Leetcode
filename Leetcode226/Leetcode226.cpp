//
// Created by cestl on 2018/4/29 0029.
//

#include "Leetcode226.h"

TreeNode *Leetcode226::invertTree(TreeNode *root) {
    if (root == nullptr)
        return nullptr;
    swap(root->left, root->right);
    if (root->left)
        invertTree(root->left);
    if (root->right)
        invertTree(root->right);
    return root;
}
