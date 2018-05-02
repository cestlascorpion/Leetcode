#include "000.config.h"
class Solution
{
  public:
    void in_order(TreeNode *root, int &sumkey)
    {
        if (!root)
            return;
        in_order(root->right, sumkey); //右 直到最右侧
        root->val += sumkey;           //根（第一次即为最右侧的节点） 更新节点值
        sumkey = root->val;
        in_order(root->left, sumkey); //左
    }
    TreeNode *convertBST(TreeNode *root)
    {
        if (!root)
            return root;
        int sumkey = 0;
        in_order(root, sumkey);
        return root;
    }
};