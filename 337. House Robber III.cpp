#include "0. config.h"

class Solution
{
  public:
    int rob(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        return robhouse(root);
    }
    int robhouse(TreeNode *root) //[begin,end)
    {
        if (root == nullptr)
            return 0;
        if (root->left == nullptr && root->right == nullptr)
            return root->val;
        int leftAndright = robhouse(root->left) + robhouse(root->right);
        int uperAndlower = (root->left ? robhouse(root->left->left) + robhouse(root->left->right) : 0) +
                           (root->right ? robhouse(root->right->left) + robhouse(root->right->right) : 0) + root->val;
        return max(leftAndright, uperAndlower);
    }
};
class Solution2
{
  public:
    int rob(TreeNode *root)
    {
        if (!root)
            return 0;
        post_travel(root);
        return root->val;
    }
    void post_travel(TreeNode *root)
    {
        int comp1 = 0, comp2 = 0;
        if (root->left)
        {
            post_travel(root->left);
            comp1 = root->left->val;
            comp2 = get(root->left->left) + get(root->left->right);
        }
        if (root->right)
        {
            post_travel(root->right);
            comp1 += root->right->val;
            comp2 += get(root->right->left) + get(root->right->right);
        }
        root->val = max(comp1, comp2 + root->val);
    }
    int get(TreeNode *root)
    {
        if (!root)
            return 0;
        return root->val;
    }
};
class Solution3
{
  public:
    int tryRob(TreeNode *root, int &l, int &r)
    {
        if (!root)
            return 0;

        int ll = 0, lr = 0, rl = 0, rr = 0;
        l = tryRob(root->left, ll, lr);
        r = tryRob(root->right, rl, rr);

        return max(root->val + ll + lr + rl + rr, l + r);
    }

    int rob(TreeNode *root)
    {
        int l, r;
        return tryRob(root, l, r);
    }
};