//
// Created by hans on 4/26/18.
//

#include "Leetcode101.h"

bool Leetcode101::isSymmetric(TreeNode *root) {
    if (root == nullptr)
        return true;
    return isSametree(root->left, root->right);
}

void Leetcode101::test101() {
    TreeNode *p;
    TreeNode p1(1);
    TreeNode p2(2);
    TreeNode p3(2);
    TreeNode p4(4);
    TreeNode p5(5);
    TreeNode p6(5);
    TreeNode p7(4);
    p1.left = &p2;
    p1.right = &p3;
    p2.left = &p4;
    p2.right = &p5;
    p3.left = &p6;
    p3.right = &p7;
    p = &p1;
    //       1
    //    2    2
    //  4  5  5  4
    cout << isSymmetric(p) << " == true?" << endl;
}

bool Leetcode101::isSametree(TreeNode *l, TreeNode *r) {
    if (!l && !r)
        return true;
    if (l && r) {
        return l->val == r->val && isSametree(l->left, r->right) && isSametree(l->right, r->left);
    } else
        return false;
}


