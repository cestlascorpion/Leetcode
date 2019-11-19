//
// Created by Wang on 2019/11/12.
//

#include "Leetcode783cn.h"

// [27,null,34,null,58,50,null,44,null,null,null]
int Leetcode783cn::minDiffInBST(TreeNode *root) {
    bool first = true;
    int pre = root->val;
    int res = INT32_MAX;
    stack<TreeNode *> s;
    TreeNode *cur = root;
    while (!s.empty() || cur != nullptr) {
        if (cur != nullptr) {
            s.push(cur);
            cur = cur->left;
        } else {
            cur = s.top();
            s.pop();
            if (first) {
                first = false;
                pre = cur->val;
            } else {
                res = min(res, cur->val - pre);
                pre = cur->val;
            }
            cur = cur->right;
        }
    }
    return res;
}
