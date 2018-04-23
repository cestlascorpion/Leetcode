#include "000.config.h"

class Solution
{
  public:
    int sumUp(TreeNode *root, int pre, int &sum)
    {
        if (root == NULL)
            return 0;
        int current = pre + root->val;
        return (current == sum) + sumUp(root->left, current, sum) + sumUp(root->right, current, sum);
    }
    int pathSum(TreeNode *root, int sum)
    {
        if (root == NULL)
            return 0;
        return sumUp(root, 0, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
};