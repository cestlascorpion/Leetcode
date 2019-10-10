//
// Created by Wang on 2019/10/13.
//

#include "Leetcode104cn.h"

int Leetcode104cn::maxDepth(TreeNode *root) {
    if (root == nullptr) {
        return 0;
    }

    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}
