//
// Created by Wang on 2019/12/18.
//

#include "Leetcode872cn.h"

bool Leetcode872cn::leafSimilar(TreeNode *root1, TreeNode *root2) {
    stack<TreeNode *> s;
    TreeNode *p = root1;
    vector<int> leaf;
    while (!s.empty() || p != nullptr) {
        if (p != nullptr) {
            s.push(p);
            p = p->left;
        } else {
            p = s.top();
            if (p->left == nullptr && p->right == nullptr) {
                leaf.push_back(p->val);
            }
            s.pop();
            p = p->right;
        }
    }

    p = root2;
    int i = 0;
    while (!s.empty() || p != nullptr) {
        if (p != nullptr) {
            s.push(p);
            p = p->left;
        } else {
            p = s.top();
            if (p->left == nullptr && p->right == nullptr) {
                if (leaf[i] != p->val) {
                    return false;
                } else {
                    ++i;
                }
            }
            s.pop();
            p = p->right;
        }
    }
    return i == leaf.size();
}
