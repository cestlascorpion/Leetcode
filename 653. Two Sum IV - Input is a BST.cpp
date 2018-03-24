#include "0. config.h"

class Solution
{
  public:
    bool findTarget(TreeNode *root, int k)
    {
        if (root == nullptr)
            return false;
        bool ans = false;
        preorder(root, root, k, ans);
        return ans;
    }
    void preorder(const TreeNode *p, const TreeNode *r, const int k, bool &ans)
    {
        if (p == nullptr)
            return;
        int tar = k - p->val;
        if (tar != p->val)
            ans = find(r, tar) || find(r, tar);
        if (ans == true)
            return;
        preorder(p->left, r, k, ans);
        if (ans == true)
            return;
        preorder(p->right, r, k, ans);
    }
    bool find(const TreeNode *root, int k)
    {
        if (root == nullptr)
            return false;
        if (root->val == k)
            return true;
        if (root->val > k)
            return find(root->left, k);
        else
            return find(root->right, k);
    }
};