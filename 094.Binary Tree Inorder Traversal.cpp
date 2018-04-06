#include "000.config.h"

class Solution
{
  public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        if (root == nullptr)
            return ans;
        stack<TreeNode *> s;
        TreeNode *p = root;
        while (!s.empty() || p != nullptr)
        {
            if (p != nullptr)
            {
                s.push(p);
                p = p->left;
            }
            else
            {
                TreeNode *t = s.top();
                s.pop();
                ans.push_back(t->val);
                p = t->right;
            }
        }
        return ans;
    }
};