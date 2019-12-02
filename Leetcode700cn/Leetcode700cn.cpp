//
// Created by Wang on 2019/12/2.
//

#include "Leetcode700cn.h"

TreeNode *Leetcode700cn::searchBST(TreeNode *root, int val) {
    if (root == nullptr) {
        return nullptr;
    }
    if (root->val == val) {
        return root;
    } else if (root->val > val) {
        return searchBST(root->left, val);
    } else {
        return searchBST(root->right, val);
    }
}
