/* 0. Binary tree
 * 中序遍历： 左 根 右
 * 前序遍历： 根 左 右
 * 后序遍历： 左 右 根
 * 层序遍历： level0->level1->...->levelmax(左 右)
 */
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};
void rePreOrder(TreeNode* root)
{
	if(root == NULL)
		return;
	std::cout<<root->val<<std::endl;
	rePreOrder(root->left);
	rePreOrder(root->right);
}
void reInorder(TreeNode* root)
{
	if(root == NULL)
		return;
	reInorder(root->left);
	std::cout<<root->val<<std::endl;
	reInorder(root->right);
}
void rePostOrder(TreeNode* root)
{
	if(root == NULL)
		return;
	rePostOrder(root->left);
	rePostOrder(root->right);
	std::cout<<root->val<<std::endl;
}
void noRePreOrder(TreeNode* root)
{
	if(root == NULL)
		return;
	TreeNode* p = root;
	stack<TreeNode*> s;
	while(!s.empty()||p)
	{
		if(p)
		{
			std::cout<<p->val<<std::endl;
			s.push(p);
			p = p->left;
		}
		else
		{
			p = s.top();
			s.pop();
			p = p->right;
		}
	}
}
void noReInorderr(TreeNode* root)
{
	if(root == NULL)
		return;
	TreeNode* p = root;
	stack<TreeNode*> s;
	while(!s.empty()||p)
	{
		if(p)
		{
			s.push(p);
			p = p->left;
		}
		else
		{
			p = s.top();
			s.pop();
			std::cout<<p->val<<std::endl;
			p = p->right;
		}
	}
}
void noRePostOrder(TreeNode* root)
{
	if(root == NULL)
		return;
	TreeNode* pCur = root;
	TreeNode* pPre = NULL;
	stack<TreeNode*> s;
	while(pCur)
	{
		if(pCur)
		{
			s.push(pCur);
			pCur = pCur->left;//把pCur移动到左子树的最下边
		}
	}
	while(!s.empty())
	{
		//走到这里，pCur都是空，并已经遍历到左子树底端(看成扩充二叉树，则空，亦是某棵树的左孩子)
		pCur = s.top();
		s.pop();
		if(pCur->right == NULL || pCur->right == pPre;)
		{
			std::cout<<pCur->val<<std::endl;
			pPre = pCur;
		}
		else
		{
			//根节点再次入栈  
			s.push(pCur);
			//进入右子树，且可肯定右子树一定不为空  
			pCur = pCur->right;
			while(pCur)
			{
				s.push(pCur);
				pCur =pCur->left;
			}
		}
	}
	
}