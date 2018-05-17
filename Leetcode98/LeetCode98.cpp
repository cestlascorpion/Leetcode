//
// Created by cestl on 2018/5/14 0014.
//

#include "LeetCode98.h"

bool LeetCode98::isValidBST(TreeNode *root) {
    if (root == nullptr)
        return true;
    int min_val = 0;
    int max_val = 0;
    return helper(root, min_val, max_val);
}

bool LeetCode98::helper(TreeNode *root, int &min_val, int &max_val) {
    if (root == nullptr)
        return true;
    int lmin = 0;
    int lmax = 0;
    int rmin = 0;
    int rmax = 0;
    bool bleft = helper(root->left, lmin, lmax);
    bool bright = helper(root->right, rmin, rmax);
    if (bleft == true && bright == true) {
        if ((root->left == nullptr || root->val > lmax) &&
            (root->right == nullptr || root->val < rmin)) {
            min_val = root->left ? lmin : root->val;
            max_val = root->right ? rmax : root->val;
            return true;
        }
    }
    return false;
}

