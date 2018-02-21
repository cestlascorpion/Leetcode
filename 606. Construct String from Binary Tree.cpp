/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
  public:
    string tree2str(TreeNode *t)
    {
        string result("");
        if (t == NULL)
            return result;
        //左右字数皆空，省略所有括号，终止遍历过程
        if (t->left == NULL && t->right == NULL)
            return to_string(t->val);
        //左右子树至少一个不为空
        if (t->left == NULL)
        {
            //左子树为空且右子树不空，需要填入括号，继续遍历
            return to_string(t->val) + "()" + "(" + tree2str(t->right) + ")";
        }
        if (t->right == NULL)
        {
            //右子树为空且左子树不为空，不需要填入括号，继续遍历
            return to_string(t->val) + "(" + tree2str(t->left) + ")";
        }
        //左右子树皆不为空
        return to_string(t->val) + "(" + tree2str(t->left) + ")" + "(" + tree2str(t->right) + ")";
    }
};