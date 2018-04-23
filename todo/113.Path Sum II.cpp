#include "000.config.h"

class Solution
{
  public:
    vector<vector<int>> pathSum(TreeNode *root, int sum)
    {
        vector<vector<int>> ans;
        if (root == nullptr)
            return ans;
        vector<int> path;
        helper(root, sum, path, ans, 0);
        return ans;
    }
    void helper(TreeNode *root, int sum, vector<int> path, vector<vector<int>> &ans, int cur)
    {
        path.push_back(root->val);
        cur += root->val;
        if (!root->left && !root->right)
        {
            if (cur == sum)
                ans.push_back(path);
            return;
        }
        if (root->left)
            helper(root->left, sum, path, ans, cur);
        if (root->right)
            helper(root->right, sum, path, ans, cur);
    }
};