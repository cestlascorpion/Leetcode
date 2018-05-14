//
// Created by cestl on 2018/5/14 0014.
//

#include "Leetcode110.h"

bool Leetcode110::isBalanced(TreeNode *root) {
    int depth = 0;
    return helper(root, depth);
}

bool Leetcode110::helper(TreeNode *root, int &depth) {
    if (root == nullptr)
        return true;
    int ldepth = 0;
    int rdepth = 0;
    if (helper(root->left, ldepth) && helper(root->right, rdepth)) {
        if (abs(ldepth - rdepth) > 1)
            return false;
        depth = max(ldepth, rdepth) + 1;
        return true;
    }
    return false;
}
