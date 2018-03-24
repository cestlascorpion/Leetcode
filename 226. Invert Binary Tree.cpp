#include "0.config.h"

class Solution
{
  public:
    TreeNode *invertTree(TreeNode *root)
    {
        if (root == NULL)
            return root;
        TreeNode *tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        if (root->left)
            invertTree(root->left);
        if (root->right)
            invertTree(root->right);
        return root;
    }
};