#include "0. config.h"

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
                ans.push_back(t->val);
                p = p->left;
            }
            else
            {
                TreeNode *t = s.top();
                s.pop();
                p = t->right;
            }
        }
        return ans;
    }
};