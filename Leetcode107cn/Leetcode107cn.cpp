//
// Created by Wang on 2019/10/13.
//

#include "Leetcode107cn.h"

vector<vector<int>> Leetcode107cn::levelOrderBottom(TreeNode *root) {
    vector<vector<int>> res;
    if (root == nullptr) {
        return res;
    }

    stack<vector<TreeNode *>> s;
    vector<TreeNode *> v;
    v.push_back(root);
    while (!v.empty()) {
        s.push(move(v)); // v -> s.top() v is empty now
        for (const auto *p:s.top()) {
            if (p->left) {
                v.push_back(p->left);
            }
            if (p->right) {
                v.push_back(p->right);
            }
        } // then v is full of TreeNode* (in the same level)
    } // deepest level

    while (!s.empty()) {
        vector<int> tmp;
        for (const auto *p:s.top()) {
            tmp.push_back(p->val);
        }
        s.pop();
        res.push_back(move(tmp));
    }
    return res;
}

vector<vector<int>> Leetcode107cn::levelOrderBottom2(TreeNode *root) {
    vector<vector<int>> res;
    if (root == nullptr) {
        return res;
    }

    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
        vector<int> tmp;
        int count = q.size();
        for (int i = 0; i < count; ++i) {
            auto *p = q.front();
            q.pop();
            tmp.push_back(p->val);
            if (p->left) q.push(p->left);
            if (p->right) q.push(p->right);
        }
        res.push_back(move(tmp));
    }
    reverse(res.begin(), res.end());
    return res;
}

void Leetcode107cn::test() {
    TreeNode p1(1);
    TreeNode p2(2);
    TreeNode p3(3);
    TreeNode p4(4);
    TreeNode p5(5);
    TreeNode p6(6);
    TreeNode p7(7);

    p1.left = &p2;
    p1.right = &p3;
    p2.left = &p4;
    p2.right = &p5;
    p3.left = &p6;
    p3.right = &p7;

    auto res = levelOrderBottom2(&p1);
    for (const auto &v:res) {
        for (const auto &n:v) {
            cout << n << " ";
        }
        cout << endl;
    }
}
