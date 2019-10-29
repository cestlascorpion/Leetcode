//
// Created by Wang on 2019/10/30.
//

#include "Leetcode270cn.h"

int Leetcode270cn::closestValue(TreeNode *root, double target) {
    if (root->val == target) {
        return root->val;
    }
    if (target > root->val && root->right == nullptr) {
        return root->val;
    }
    if (target < root->val && root->left == nullptr) {
        return root->val;
    }

    if (target > root->val) {
        auto min = closestValue(root->right, target);
        if (abs(target - min) < target - root->val) {
            return min;
        } else {
            return root->val;
        }
    } else {
        auto min = closestValue(root->left, target);
        if (abs(target - min) < root->val - target) {
            return min;
        } else {
            return root->val;
        }
    }
}
