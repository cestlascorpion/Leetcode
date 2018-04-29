//
// Created by cestl on 2018/4/29 0029.
//

#include "Leetcode112.h"

bool Leetcode112::hasPathSum(TreeNode *root, int sum) {
    if (root == nullptr)
        return false;
    bool ans = false;
    helper(root, sum, 0, ans);
    return ans;
}

void Leetcode112::helper(TreeNode *root, int sum, int cur, bool &ans) {
    cur += root->val;
    if (!root->left && !root->right) {
        if (cur == sum)
            ans = true;
        return;
    }
    if (root->left)
        helper(root->left, sum, cur, ans);
    if (root->right)
        helper(root->right, sum, cur, ans);
}
