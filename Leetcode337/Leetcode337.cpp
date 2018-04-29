//
// Created by cestl on 2018/4/29 0029.
//

#include "Leetcode337.h"

int Leetcode337::tryRob(TreeNode *root, int &l, int &r) {
    if (root == nullptr)
        return 0;

    int ll = 0, lr = 0, rl = 0, rr = 0;
    l = tryRob(root->left, ll, lr);
    r = tryRob(root->right, rl, rr);

    return max(root->val + ll + lr + rl + rr, l + r);
}

int Leetcode337::rob(TreeNode *root) {
    int l, r;
    return tryRob(root, l, r);
}
