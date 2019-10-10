//
// Created by Wang on 2019/10/13.
//

#include "Leetcode257cn.h"

vector<string> Leetcode257cn::binaryTreePaths(TreeNode *root) {
    vector<string> res;
    if (root == nullptr) {
        return res;
    }
    string path;
    DFS(root, path, res);
    return res;
}

void Leetcode257cn::DFS(TreeNode *root, string path, vector<string> &res) {
    if (root->left == nullptr && root->right == nullptr) {
        res.push_back(path + to_string(root->val));
        return;
    }

    if (root->left != nullptr) {
        DFS(root->left, path + to_string(root->val) + "->", res);
    }
    if (root->right != nullptr) {
        DFS(root->right, path + to_string(root->val) + "->", res);
    }
}
