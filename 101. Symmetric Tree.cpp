#include "0. config.h"

class Solution
{
  public:
    bool helper(TreeNode *left, TreeNode *right)
    {
        if (left == NULL && right == NULL)
            return true;
        else
        {
            if (left == NULL && right != NULL)
                return false;
            if (left != NULL && right == NULL)
                return false;

            return left->val == right->val && helper(left->left, right->right) && helper(left->right, right->left);
        }
    }
    bool isSymmetric(TreeNode *root)
    {
        if (!root)
            return true;
        else
            return helper(root->left, root->right);
    }
};