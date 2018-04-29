//
// Created by cestl on 2018/4/29 0029.
//

#include "leetcode437.h"

int leetcode437::pathSum2(TreeNode *root, int sum) {
    int ans = 0;
    if (root == nullptr)
        return ans;
    return helper2(root, 0, sum) +
           pathSum2(root->left, sum) +
           pathSum2(root->right, sum);
    return ans;
}

int leetcode437::helper2(TreeNode *root, int pre, int &sum) {
    if (root == nullptr)
        return 0;
    int cur = pre + root->val;
    //以当前节点为根节点的二叉树中满足条件的数量 +
    //以左右节点为根节点的二叉树中满足条件的数量
    return (cur == sum) +
           helper2(root->left, cur, sum) +
           helper2(root->right, cur, sum);
}

int leetcode437::pathSum(TreeNode *root, int sum) {
    if (root == nullptr)
        return 0;
    return helper(root, sum) +
           pathSum(root->left, sum) +
           pathSum(root->right, sum);
}

int leetcode437::helper(TreeNode *node, int sum) {
    if (node == nullptr)
        return 0;
    //当前节点是否满足条件（1/0） +
    // 当前节点和左子树中满足条件的数量 +
    // 当前节点和右子树中满足条件的数量
    return (node->val == sum ? 1 : 0) +
           helper(node->left, sum - node->val) +
           helper(node->right, sum - node->val);
}
