/* 543. Diameter of Binary Tree
 * 如果最长路径包含根节点，则最长路径必须是深度（根 - >右）+深度（根 - >左）
 * 如果最长的路径不包含根节点，则将此问题分为2个子问题：分别将左子数和右子树设置为新根，并重复步骤1
 */
#include "0. config.h"

class Solution
{
  public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int res = depth(root->left) + depth(root->right);
        return max(res, max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)));
    }

    int depth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        return 1 + max(depth(root->left), depth(root->right));
    }
};