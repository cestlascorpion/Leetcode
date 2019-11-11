//
// Created by Wang on 2019/11/10.
//

#ifndef LEETCODE_LEETCODE236CN_H
#define LEETCODE_LEETCODE236CN_H

#include <config.h>

class Leetcode236cn {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (root == nullptr || root == p || root == q) {
            return root;
        }

        auto *left = lowestCommonAncestor(root->left, p, q);
        auto *right = lowestCommonAncestor(root->right, p, q);

        if (left && right) {
            return root;
        } else {
            if (left) {
                return left;
            }
            if (right) {
                return right;
            }
            return nullptr;
        }
    }

    TreeNode *lowestCommonAncestor_bad(TreeNode *root, TreeNode *p, TreeNode *q);

private:
    void required_path(TreeNode *root, TreeNode *p, TreeNode *q, vector<TreeNode *> path,
                       vector<vector<TreeNode *>> &paths);
};

#endif // LEETCODE_LEETCODE236CN_H
