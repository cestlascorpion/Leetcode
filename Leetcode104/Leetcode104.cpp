//
// Created by hans on 4/26/18.
//

#include "Leetcode104.h"

int Leetcode104::maxDepth(TreeNode *root) {
    if (root == nullptr)
        return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

void Leetcode104::test104() {
    TreeNode *p;
    TreeNode p1(1);
    TreeNode p2(2);
    TreeNode p3(3);
    TreeNode p4(4);
    TreeNode p5(5);
    p1.left = &p2;
    p1.right = &p3;
    p2.left = &p4;
    p2.right = &p5;
    p = &p1;
    cout << maxDepth(p) << " == 3?" << endl;
    //      1
    //    2   3
    //  4  5
}
