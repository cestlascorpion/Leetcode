//
// Created by cestl on 2018/4/29 0029.
//

#include "Leetcode113.h"

vector<vector<int>> Leetcode113::pathSum(TreeNode *root, int sum) {
    vector<vector<int>> ans;
    if (root == nullptr)
        return ans;
    vector<int> path;
    helper(root, sum, 0, path, ans);
    return ans;
}

void Leetcode113::helper(TreeNode *root, int sum, int cur,
                         vector<int> &path, vector<vector<int>> &ans) {
    cur += root->val;
    path.push_back(root->val);
    if (!root->left && !root->right) {
        if (sum == cur) {
            ans.push_back(path);
        }
        path.pop_back();
        return;
    }

    if (root->left) {
        helper(root->left, sum, cur, path, ans);
    }
    if (root->right) {
        helper(root->right, sum, cur, path, ans);
    }
    path.pop_back();
}
