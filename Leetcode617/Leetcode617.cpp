//
// Created by cestl on 2018/5/3 0003.
//

#include "Leetcode617.h"

TreeNode *Leetcode617::mergeTrees(TreeNode *t1, TreeNode *t2) {
    if (t1 == nullptr)
        return t2;
    if (t2 == nullptr)
        return t1;

    TreeNode *ans = new TreeNode(t1->val + t2->val);
    ans->left = mergeTrees(t1->left, t2->left);
    ans->right = mergeTrees(t1->right, t2->right);
    return ans;
}
