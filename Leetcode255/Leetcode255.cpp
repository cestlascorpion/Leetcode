//
// Created by hans on 4/26/18.
//

#include "Leetcode255.h"

bool Leetcode255::isValidBST(TreeNode *root) {
    if (root == nullptr)
        return true;
    vector<int> ans;
    TreeNode *p = root;
    stack<TreeNode *> s;
    while (!s.empty() || p != nullptr) {
        if (p != nullptr) {
            s.push(p);
            p = p->left;
        } else {
            p = s.top();
            s.pop();
            ans.push_back(p->val);
            p = p->right;
        }
    }
    int val = ans[0];
    for (int i = 1; i < ans.size(); ++i) {
        if (val >= ans[i])
            return false;
        val = ans[i];
    }
    return true;
}

void Leetcode255::test255() {
    TreeNode *p;
    TreeNode p1(5);
    TreeNode p2(3);
    TreeNode p3(6);
    TreeNode p4(1);
    TreeNode p5(7);
    p1.left = &p2;
    p1.right = &p3;
    p2.left = &p4;
    p2.right = &p5;
    p = &p1;
    cout << isValidBST(p) << " == false?" << endl;
    cout << isValidBST(p) << " == false?" << endl;
    cout << isValidBST3(p) << " == false?" << endl;
    p5.val = 4;
    cout << isValidBST(p) << " == true?" << endl;
    cout << isValidBST(p) << " == true?" << endl;
    cout << isValidBST3(p) << " == ture?" << endl;
}

bool Leetcode255::isValidBST2(TreeNode *root) {
    long minVal = numeric_limits<long>::min();
    long maxVal = numeric_limits<long>::max();
    return helper2(root, minVal, maxVal);
}


bool Leetcode255::helper2(TreeNode *root, long maxV, long minV) {
    if (root == nullptr)
        return true;
    if (minV >= root->val || maxV <= root->val)
        return false;
    return helper2(root->left, minV, root->val)
           && helper2(root->right, root->val, maxV);
}

bool Leetcode255::isValidBST3(TreeNode *root) {
    long pre = numeric_limits<long>::min();
    return helper3(root, pre);
}

bool Leetcode255::helper3(TreeNode *root, long &pre) {
    if (root == nullptr)
        return true;

    bool left = helper3(root->left, pre);

    if (pre >= root->val)
        return false;
    pre = root->val;

    bool right = helper3(root->right, pre);
    return left & right;

}
