/* 617. Merge Two Binary Trees
 * 递归 返回根节点  处理左子树 处理右子树
 * 递归就是包子馅的包子。它的极限是馒头。 --Rockie Yang
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1==NULL)
            return t2;
        else if(t2==NULL)
            return t1;
        else{
            TreeNode* res = new TreeNode(t1->val+t2->val);
            res->left = mergeTrees(t1->left,t2->left);
            res->right = mergeTrees(t1->right,t2->right);
            return res;
        }
    }
};