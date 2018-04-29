//
// Created by cestl on 2018/4/29 0029.
//

#include "Leetcode337.h"

int Leetcode337::rob(TreeNode *root) {
    int l, r;
    return tryRob(root, l, r);
}

int Leetcode337::tryRob(TreeNode *root, int &l, int &r) {
    if (root == nullptr)
        return 0;

    int ll = 0, lr = 0;                 //左孩子的左右孩子的最优解
    int rl = 0, rr = 0;                 //右孩子的左右孩子的最优解
    l = tryRob(root->left, ll, lr);     //左孩子的最优解
    r = tryRob(root->right, rl, rr);    //右孩子的最优解
    // 当前节点的最优解
    return max(root->val + ll + lr + rl + rr, l + r);
}

pair<int, int> Leetcode337::tryrob2(TreeNode *root) {
    if (root == nullptr)
        return make_pair(0, 0);

    auto left = tryrob2(root->left);
    auto right = tryrob2(root->right);
    // maximum amount including root
    int n0 = left.second + right.second + root->val;
    // maximum amount excluding root
    int n1 = left.first + right.first;
    return {max(n0, n1), n1};
}

int Leetcode337::rob2(TreeNode *root) {
    auto r = tryrob2(root);
    return r.first;
}
