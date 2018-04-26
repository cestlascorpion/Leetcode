//
// Created by hans on 4/26/18.
//

#include "Leetcode102.h"

vector<vector<int>> Leetcode102::levelOrder(TreeNode *root) {
    vector<vector<int>> ans;
    TreeNode *p = root;
    if (p == nullptr)
        return ans;
    queue<TreeNode *> q;
    q.push(p);
    while (!q.empty()) {
        int n = q.size();
        vector<int> temp;
        for (int i = 0; i < n; ++i) {
            p = q.front();
            q.pop();
            temp.push_back(p->val);
            if (p->left)
                q.push(p->left);
            if (p->right)
                q.push(p->right);
        }
        ans.push_back(temp);
    }
    return ans;
}

void Leetcode102::test102() {
    TreeNode p0(0);
    TreeNode p1(1);
    TreeNode p2(2);
    TreeNode p3(3);
    TreeNode p4(4);
    TreeNode p5(5);
    TreeNode p6(6);
    TreeNode *p = &p0;
    p0.left = &p1;
    p0.right = &p2;

    p1.left = &p3;
    p1.right = &p4;

    p2.left = &p5;
    p2.right = &p6;
    vector<vector<int>> ans = levelOrder(p);
    for (auto item:ans) {
        for (auto jtem:item) { cout << jtem << " "; }
        cout << endl;
    }
    cout<<endl;
}

