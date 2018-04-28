//
// Created by cestl on 2018/4/28 0028.
//

#include "Leetcode105.h"

TreeNode *Leetcode105::buildTree(vector<int> &preorder, vector<int> &inorder) {
    if (preorder.empty() || inorder.empty())
        return nullptr;
    TreeNode *ans = new TreeNode(preorder[0]);
    if (preorder.size() == 1)
        return ans;
    int pos = 0;
    for (pos = 0; pos < inorder.size(); ++pos) {
        if (inorder[pos] == preorder[0])
            break;
    }
    vector<int> lpreorder(pos, 0);
    vector<int> linorder(pos, 0);
    vector<int> rpreorder(preorder.size() - pos - 1);
    vector<int> rinorder(inorder.size() - pos - 1);

    for (int i = 0; i < pos; ++i) {
        lpreorder[i] = preorder[i + 1];
        linorder[i] = inorder[i];
    }

    ans->left = buildTree(lpreorder, linorder);

    for (int i = 0; i < preorder.size() - pos - 1; ++i) {
        rpreorder[i] = preorder[i + 1 + pos];
        rinorder[i] = inorder[i + pos + 1];
    }

    ans->right = buildTree(rpreorder, rinorder);

    return ans;
}

TreeNode *Leetcode105::buildTree2(vector<int> &preorder, vector<int> &inorder) {
    if (preorder.empty() || inorder.empty())
        return nullptr;
    return dfs(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
}

TreeNode *Leetcode105::dfs(vector<int> &preorder, vector<int> &inorder, int pl, int pr, int il, int ir) {
    if (pl > pr || il > ir)
        return nullptr;

    TreeNode *p = new TreeNode(preorder[pl]);

    if (pl == pr && il == ir)
        return p;

    int pos;
    int key = preorder[pl];

    for (int i = il; i <= ir; ++i) {
        if (inorder[i] == key) {
            pos = i;
            break;
        }
    }

    p->left = dfs(preorder, inorder, pl + 1, pl + (pos - il), il, pos - 1);
    p->right = dfs(preorder, inorder, pl + (pos - il) + 1, pr, pos + 1, ir);
    return p;
}

