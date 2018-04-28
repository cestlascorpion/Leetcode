//
// Created by cestl on 2018/4/28 0028.
//

#include "Leetcode94.h"

vector<int> Leetcode94::inorderTraversal(TreeNode *root) {
    vector<int> ans;
    if (root == nullptr)
        return ans;

    TreeNode *p = root;
    stack<TreeNode *> s;

    while (!s.empty() || p != nullptr) {
        if (p != nullptr) {
            s.push(p);
            p = p->left;
        } else {
            p = s.top();
            s.pop();
            ans.push_back(p->val);
            p = p->right;
        }
    }
    return ans;
}
