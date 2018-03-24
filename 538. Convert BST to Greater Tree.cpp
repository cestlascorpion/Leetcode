/* 538. Convert BST to Greater Tree
 * BST 二叉搜索树 左节点<根节点<右节点
 * 所以左节点需要加上根节点和右节点的值，根节点需要加上右节点的值
 * 采用后序遍历 右 根 左 依次把后面要遍历的节点需要加和的值取出、相加即可
 */
#include "0. config.h"

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