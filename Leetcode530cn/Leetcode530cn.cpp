//
// Created by Wang on 2019/11/29.
//

#include "Leetcode530cn.h"

int Leetcode530cn::getMinimumDifference(TreeNode *root) {
    int min = INT64_MAX;
    TreeNode *pre = nullptr;
    helper(root, pre, min);
    return min;
}
void Leetcode530cn::helper(TreeNode *cur, TreeNode *&pre, int &min) {
    if (cur == nullptr) {
        return;
        helper(cur->left, pre, min);
        if (pre != nullptr) {
            min = std::min(cur->val - pre->val, min);
        }
        pre = cur;
        helper(cur->right, pre, min);
    }
