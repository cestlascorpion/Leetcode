//
// Created by cestl on 2018/5/2 0002.
//

#include "Leetcode538.h"

TreeNode *Leetcode538::convertBST(TreeNode *root) {
    if (root == nullptr)
        return nullptr;
    stack<TreeNode *> s;
    TreeNode *p = root;
    int sum = 0;
    while (!s.empty() || p != nullptr) {
        if (p != nullptr) {
            s.push(p);
            p = p->right;
        } else {
            p = s.top();
            s.pop();
            int temp = p->val + sum;
            sum = temp;
            p->val = temp;
            p = p->left;
        }
    }
    return root;
}

TreeNode *Leetcode538::convertBST2(TreeNode *root) {
    if (!root)
        return root;
    int sumkey = 0;
    helper(root, sumkey);//右→左→根的遍曆順序
    return root;
}

void Leetcode538::helper(TreeNode *root, int &sumkey) {
    if (!root)
        return;
    helper(root->right, sumkey); //右 直到最右侧
    root->val += sumkey;         //根（第一次即为最右侧的节点） 更新节点值
    sumkey = root->val;
    helper(root->left, sumkey); //左
}
