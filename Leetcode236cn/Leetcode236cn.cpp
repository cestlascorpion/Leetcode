//
// Created by Wang on 2019/11/10.
//

#include "Leetcode236cn.h"

TreeNode *Leetcode236cn::lowestCommonAncestor_bad(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (root == nullptr || root == p || root == q) {
        return root;
    }

    vector<vector<TreeNode *>> paths;
    paths.resize(2);

    vector<TreeNode *> path;
    required_path(root, p, q, path, paths);

    for (int i = 1; i < paths[0].size() || i < paths[1].size(); ++i) {
        if (i == paths[0].size())
            return paths[0][i - 1];
        if (i == paths[1].size())
            return paths[1][i - 1];

        if (paths[0][i] != paths[1][i]) {
            return paths[0][i - 1];
        }
    }
    return nullptr;
}
void Leetcode236cn::required_path(TreeNode *root, TreeNode *p, TreeNode *q, vector<TreeNode *> path,
                                  vector<vector<TreeNode *>> &paths) {
    if (root == nullptr) {
        return;
    }
    path.push_back(root);
    if (root->val == p->val) {
        paths[0] = path;
    }
    if (root->val == q->val) {
        paths[1] = path;
    }
    if (paths[0].empty() || paths[1].empty()) {
        required_path(root->left, p, q, path, paths);
        required_path(root->right, p, q, path, paths);
    }
}
