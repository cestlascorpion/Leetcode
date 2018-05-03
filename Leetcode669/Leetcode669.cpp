//
// Created by cestl on 2018/5/3 0003.
//

#include "Leetcode669.h"

TreeNode *Leetcode669::trimBST(TreeNode *root, int L, int R) {
    if (root == nullptr)
        return nullptr;
    if (root->val >= L && root->val <= R) {
        root->left = trimBST(root->left, L, R);
        root->right = trimBST(root->right, L, R);
    } else if (root->val < L) {
        root = trimBST(root->right, L, R);
    } else {
        root = trimBST(root->left, L, R);
    }
    return root;
}
