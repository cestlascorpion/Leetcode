#include "000.config.h"

class Solution
{
  public:
    int minDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        if (!root->left)
            return 1 + minDepth(root->right);
        if (!root->right)
            return 1 + minDepth(root->left);
        return 1 + min(minDepth(root->right), minDepth(root->left));
    }
};