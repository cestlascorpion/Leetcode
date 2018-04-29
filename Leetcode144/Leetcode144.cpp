//
// Created by cestl on 2018/4/29 0029.
//

#include "Leetcode144.h"

vector<int> Leetcode144::preorderTraversal(TreeNode *root) {
    vector<int> ans;
    if (root == nullptr)
        return ans;
    stack<TreeNode *> s;
    TreeNode *p = root;
    while (!s.empty() || p != nullptr) {
        if (p != nullptr) {
            s.push(p);
            ans.push_back(p->val);
            p = p->left;
        } else {
            p = s.top();
            s.pop();
            p = p->right;
        }
    }
    return ans;
}
