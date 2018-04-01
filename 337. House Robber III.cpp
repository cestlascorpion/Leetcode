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
class Solution2s
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