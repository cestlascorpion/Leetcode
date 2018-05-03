//
// Created by cestl on 2018/5/3 0003.
//

#include "Leetcode543.h"

int Leetcode543::diameterOfBinaryTree(TreeNode *root) {
    int ans = 0;
    if (root == nullptr)
        return ans;

    ans = helper(root->left) + helper(root->right);
    return max(ans, max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)));
}

int Leetcode543::helper(TreeNode *root) {
    if (root == nullptr)
        return 0;
    return 1 + max(helper(root->left), helper(root->right));
}

int Leetcode543::diameterOfBinaryTree2(TreeNode *root) {
    int ans = 0;
    if (root == nullptr)
        return ans;
    helper2(root, ans);
    return ans;
}

int Leetcode543::helper2(TreeNode *root, int &ans) {
    if (root == nullptr)
        return 0;
    int cl, cr;
    cl = helper2(root->left, ans);
    cr = helper2(root->right, ans);
    ans = max(cl + cr, ans);
    return 1 + max(cl, cr);
}
