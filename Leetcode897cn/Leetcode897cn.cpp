//
// Created by Wang on 2019/12/18.
//

#include "Leetcode897cn.h"

TreeNode* Leetcode897cn::increasingBST(TreeNode* root) {
    stack<TreeNode *> s;
    TreeNode *p = root;
    vector<TreeNode *> nodes;
    while (!s.empty() || p != nullptr) {
        if (p != nullptr) {
            s.push(p);
            p = p->left;
        } else {
            p = s.top();
            s.pop();
            nodes.push_back(p);
            p = p->right;
        }
    }
    nodes.push_back(nullptr);
    for (int i = 0; i < nodes.size(); ++i) {
        nodes[i]->left = nullptr;
        nodes[i]->right = nodes[i + 1];
    }
    return nodes.front();
}
