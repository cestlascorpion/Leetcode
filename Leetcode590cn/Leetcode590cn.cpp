//
// Created by Wang on 2019/11/30.
//

#include "Leetcode590cn.h"

vector<int> Leetcode590cn::postorder(Node *root) {
    vector<int> res;
    helper(root, res);
    return res;
}

void Leetcode590cn::helper(Node *root, vector<int> &res) {
    if (root == nullptr) {
        return;
    }
    for (const auto &node : root->children) {
        helper(node, res);
    }
    res.push_back(root->val);
}
vector<int> Leetcode590cn::postorder2(Node *root) {
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
    reverse(res.begin(), res.end());
    return res;
}
