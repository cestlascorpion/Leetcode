//
// Created by cestl on 2018/4/28 0028.
//

#include "Leetcode116.h"

void Leetcode116::connect(TreeLinkNode *root) {
    if (root == nullptr)
        return;

    queue<TreeLinkNode *> q;
    TreeLinkNode *p = root;
    q.push(p);
    while (!q.empty()) {
        int n = q.size();
        vector<TreeLinkNode *> v;
        for (int i = 0; i < n; ++i) {
            p = q.front();
            q.pop();
            v.push_back(p);
            if (p->left)
                q.push(p->left);
            if (p->right)
                q.push(p->right);
        }
        for (int i = 0; i < n; ++i) {
            if (i != n - 1) {
                v[i]->next = v[i + 1];
            } else {
                v[i]->next = nullptr;
            }
        }
    }
}
