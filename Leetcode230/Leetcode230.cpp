//
// Created by cestl on 2018/4/28 0028.
//

#include "Leetcode230.h"

int Leetcode230::kthSmallest(TreeNode *root, int k) {
    TreeNode *p = root;
    stack<TreeNode *> s;
    int cnt = 0;
    while (!s.empty() || p != nullptr) {
        if (p != nullptr) {
            s.push(p);
            p = p->left;
        } else {
            p = s.top();
            s.pop();
            ++cnt;
            if (cnt == k)
                return p->val;
            p = p->right;
        }
    }
    return 0;
}
