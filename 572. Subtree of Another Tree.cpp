#include "0. config.h"

class Solution
{
  public:
    bool isSametree(TreeNode *s, TreeNode *t)
    {
        if (s == NULL && t == NULL)
            return true;
        else
        {
            if (s == NULL || t == NULL)
                return false;
            else
                return s->val == t->val && isSametree(s->left, t->left) && isSametree(s->right, t->right);
        }
    }
    bool isSubtree(TreeNode *s, TreeNode *t)
    {
        if (s == NULL)
            return false;
        if (isSametree(s, t)) //检查两棵树否相同
            return true;
        return isSubtree(s->left, t) || isSubtree(s->right, t); //不相同检查左子树和右子树是否和t相同
    }
};