#include "000.config.h"

class Solution
{
  public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        TreeNode *p = root;
        if (p == nullptr)
            return ans;
        queue<TreeNode *> q;
        q.push(p);
        while (!q.empty())
        {
            int n = q.size();
            vector<int> temp;
            for (int i = 0; i < n; i++)
            {
                p = q.front();
                q.pop();
                temp.push_back(p->val);
                if (p->left)
                    q.push(p->left);
                if (p->right)
                    q.push(p->right);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};