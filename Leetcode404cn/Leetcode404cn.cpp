//
// Created by Wang on 2019/11/27.
//

#include "Leetcode404cn.h"

int Leetcode404cn::sumOfLeftLeaves(TreeNode *root) {
    if(root == nullptr){
        return 0;
    }
    return helper(root->left, true) + helper(root->right, false);
}

int Leetcode404cn::helper(TreeNode *root, bool l) {
    if(root == nullptr) {
        return 0;
    }
    if(root->left == nullptr && root->right == nullptr && l){
        return root->val;
    }
    return helper(root->left, true) + helper(root->right, false);
}
