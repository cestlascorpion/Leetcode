//
// Created by cestl on 2018/5/3 0003.
//

#include "Leetcode653.h"

bool Leetcode653::findTarget(TreeNode *root, int k) {
    bool ans = false;
    if (root == nullptr)
        return ans;
    preorder(root, root, k, ans);
    return ans;
}

void Leetcode653::preorder(const TreeNode *p, const TreeNode *r, const int k, bool &ans) {
    if (p == nullptr)
        return;
    int tar = k - p->val;
    if (tar != p->val)
        ans = find(r, tar) || find(r, tar);
    if (ans == true)
        return;
    preorder(p->left, r, k, ans);
    if (ans == true)
        return;
    preorder(p->right, r, k, ans);
}

bool Leetcode653::find(const TreeNode *root, int k) {
    if (root == nullptr)
        return false;
    if (root->val == k)
        return true;
    if (root->val > k)
        return find(root->left, k);
    else
        return find(root->right, k);
}
