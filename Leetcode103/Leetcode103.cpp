//
// Created by cestl on 2018/4/28 0028.
//

#include "Leetcode103.h"

vector<vector<int>> Leetcode103::zigzagLevelOrder(TreeNode *root) {
    vector<vector<int>> ans;
    if (root == nullptr)
        return ans;

    TreeNode *p = root;
    queue<TreeNode *> q;
    bool Zigzag = true;
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
        if (Zigzag == false)
            reverse(temp.begin(), temp.end());
        ans.push_back(temp);
        Zigzag = !Zigzag;
    }
    return ans;
}
