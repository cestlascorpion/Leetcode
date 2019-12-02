//
// Created by Wang on 2019/11/30.
//

#include "Leetcode589cn.h"

vector<int> Leetcode589cn::preorder(Node *root) {
    vector<int> res;
    if (root == nullptr) {
        return res;
    }
    helper(root, res);
    return res;
}
void Leetcode589cn::helper(Node *root, vector<int> &ans) {
    if (root == nullptr) {
        return;
    }
    ans.push_back(root->val);
    for (const auto &node : root->children) {
        helper(node, ans);
    }
}
vector<int> Leetcode589cn::preorder2(Node *root) {
    if (root == nullptr)
        return vector<int>();

    vector<int> res;
    stack<Node *> s;
    Node *p = root;
    while (!s.empty() || p != nullptr) {
        if (p != nullptr) {
            res.push_back(p->val);
            for (auto iter = p->children.rbegin(); iter != p->children.rend(); ++iter) {
                s.push(*iter);
            }
            p = nullptr;
        } else {
            p = s.top();
            s.pop();
        }
    }
    return res;
}
