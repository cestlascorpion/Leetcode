//
// Created by Wang on 2019/10/20.
//

#include "Leetcode563cn.h"

int Leetcode563cn::findTilt(TreeNode *root) {
    if (root == nullptr) {
        return 0;
    }
    int res = 0;
    helper(root, res);
    return res;
}

int Leetcode563cn::helper(TreeNode *root, int &tilt) {
    if (root == nullptr) {
        return 0;
    }
    int left = helper(root->left, tilt);
    int right = helper(root->right, tilt);
    tilt += abs(left - right);
    int sum = root->val + left + right;
    cout << "val " << root->val << " left " << left << " right " << right << " tilt " << tilt << endl;
    return sum;
}
