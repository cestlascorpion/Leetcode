//
// Created by cestl on 2018/4/29 0029.
//

#include "Leetcode145.h"

vector<int> Leetcode145::postorderTraversal(TreeNode *root) {
    vector<int> ans;
    if (root == nullptr)
        return ans;
    stack<TreeNode *> s;
    TreeNode *p = root;
    while (!s.empty() || p != nullptr) {
        if (p != nullptr) {
            s.push(p);
            ans.push_back(p->val);
            p = p->right;
        } else {
            p = s.top();
            s.pop();
            p = p->left;
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

vector<int> Leetcode145::postorderTraversal2(TreeNode *root) {
    vector<int> ans;
    if (root == nullptr)
        return ans;
    stack<TreeNode *> s;
    TreeNode *cur = root;
    TreeNode *pre = nullptr;
    while (!s.empty() || cur != nullptr) {
        if (cur != nullptr) {
            s.push(cur);
            cur = cur->left;
        } else {
            cur = s.top();
            s.pop();
            if (cur->right == nullptr || cur->right == pre) {
                ans.push_back(cur->val);
                pre = cur;
                cur = nullptr;
            } else {
                s.push(cur);
                cur = cur->right;
            }
        }
    }
    return ans;
}
