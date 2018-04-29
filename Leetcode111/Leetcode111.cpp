//
// Created by cestl on 2018/4/29 0029.
//

#include "Leetcode111.h"

int Leetcode111::minDepth(TreeNode *root) {
    if (root == nullptr)
        return 0;
    if (!root->left)
        return 1 + minDepth(root->right);
    if (!root->right)
        return 1 + minDepth(root->left);
    return 1 + min(minDepth(root->right), minDepth(root->left));
}
    