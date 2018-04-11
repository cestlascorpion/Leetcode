#include "000.config.h"

class Solution
{
  public:
    bool hasPathSum(TreeNode *root, int sum)
    {
        if (root == nullptr)
            return false;

        bool ans = false;
        helper(root, sum, 0, ans);
        return ans;
    }
    void helper(TreeNode *root, int &sum, int cur, bool &ans)
    {
        if (ans == true)
            return;
        cur += root->val;
        if (!root->left && !root->right)
        {
            if (sum == cur)
                ans = true;
            return;
        }
        if (root->left)
            helper(root->left, sum, cur, ans);
        if (root->right)
            helper(root->right, sum, cur, ans);
    }
};
class Solution2
{
  public:
    bool hasPathSum(TreeNode *root, int sum)
    {
        if (root == NULL)
            return false;
        if (root->val == sum && root->left == NULL && root->right == NULL)
            return true;
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};