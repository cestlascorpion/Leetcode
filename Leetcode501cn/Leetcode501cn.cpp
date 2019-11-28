//
// Created by Wang on 2019/11/28.
//

#include "Leetcode501cn.h"

vector<int> Leetcode501cn::findMode(TreeNode *root) {
    if (root == nullptr)
        return vector<int>();
    unordered_map<int, int> dict;
    stack<TreeNode *> st;
    TreeNode *p = root;
    while (!st.empty() || p != nullptr) {
        if (p != nullptr) {
            st.push(p);
            p = p->left;
        } else {
            p = st.top();
            st.pop();
            ++dict[p->val];
            p = p->right;
        }
    }
    auto cmp = [](const pair<const int, int> &p1, const pair<const int, int> &p2) -> bool {
        return p1.second < p2.second;
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
    for (auto &pair : dict) {
        pq.emplace(pair);
    }
    int max = pq.top().second;
    vector<int> res;
    while (!pq.empty() && pq.top().second == max) {
        res.push_back(pq.top().first);
        pq.pop();
    }
    return res;
}

vector<int> Leetcode501cn::findMode2(TreeNode *root) {
    if (root == nullptr) {
        return vector<int>();
    }
    int cnt = 0;
    int max = 0;
    TreeNode *pre = nullptr;
    vector<int> ans;
    helper(root, pre, cnt, max, ans);
    return ans;
}

void Leetcode501cn::helper(TreeNode *cur, TreeNode *&pre, int &cnt, int &max, vector<int> &ans) {
    if (cur->left) {
        helper(cur->left, pre, cnt, max, ans);
    }
    if (pre == nullptr) {
        cnt = 1;
    } else {
        if (pre->val == cur->val) {
            ++cnt;
        } else {
            cnt = 1;
        }
    }

    if (cnt == max) {
        ans.push_back(cur->val);
    } else if (cnt > max) {
        ans.clear();
        ans.push_back(cur->val);
        max = cnt;
    }

    pre = cur;

    if (cur->right) {
        helper(cur->right, pre, cnt, max, ans);
    }
}
