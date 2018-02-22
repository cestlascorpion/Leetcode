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
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> bnode;
        if (root == NULL)
            return bnode;
        TreeNode *pCur = root;
        TreeNode *pPre = NULL;
        stack<TreeNode *> s;
        while (pCur)
        {
            if (pCur)
            {
                s.push(pCur);
                pCur = pCur->left; //把pCur移动到左子树的最下边
            }
        }
        while (!s.empty())
        {
            //走到这里，pCur都是空，并已经遍历到左子树底端(看成扩充二叉树，则空，亦是某棵树的左孩子)
            pCur = s.top();
            s.pop();
            if (pCur->right == NULL || pCur->right == pPre)
            {
                //std::cout<<pCur->val<<std::endl;
                bnode.push_back(pCur->val);
                pPre = pCur; //pPre指向打印过的节点
            }
            else
            {
                //根节点再次入栈
                s.push(pCur);
                //进入右子树，且可肯定右子树一定不为空
                pCur = pCur->right;
                while (pCur)
                {
                    s.push(pCur);
                    pCur = pCur->left;
                }
            }
        }
        return bnode;
    }
};