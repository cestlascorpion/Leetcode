/* 0. Binary tree
 * 中序遍历： 左 根 右
 * 前序遍历： 根 左 右
 * 后序遍历： 左 右 根
 * 层序遍历： level0->level1->...->levelmax(左 右)
 */
#include "0. config.h"

void rePreOrder(TreeNode *root)
{
	if (root == NULL)
		return;
	std::cout << root->val << std::endl;
	rePreOrder(root->left);
	rePreOrder(root->right);
}
void reInorder(TreeNode *root)
{
	if (root == NULL)
		return;
	reInorder(root->left);
	std::cout << root->val << std::endl;
	reInorder(root->right);
}
void rePostOrder(TreeNode *root)
{
	if (root == NULL)
		return;
	rePostOrder(root->left);
	rePostOrder(root->right);
	std::cout << root->val << std::endl;
}
void noRePreOrder(TreeNode *root)
{
	if (root == NULL)
		return;
	TreeNode *p = root;
	stack<TreeNode *> s;

	while (!s.empty() || p)
	{
		if (p)
		{
			std::cout << p->val << std::endl;
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
void noReInorderr(TreeNode *root)
{
	if (root == NULL)
		return;
	TreeNode *p = root;
	stack<TreeNode *> s;

	while (!s.empty() || p)
	{
		if (p)
		{
			s.push(p);
			p = p->left;
		}
		else
		{
			p = s.top();
			s.pop();
			std::cout << p->val << std::endl;
			p = p->right;
		}
	}
}
void noRePostOrder(TreeNode *root)
{
	if (root == NULL)
		return;
	TreeNode *temp = root;
	TreeNode *pre = NULL;
	stack<TreeNode *> s;

	while (temp || !s.empty())
	{
		if (temp)
		{
			s.push(temp);
			temp = temp->left;
		}
		else
		{
			TreeNode *topNode = s.top(); //没有出栈
			if (topNode->right && pre != topNode->right)
				temp = topNode->right;
			else
			{
				std::cout << topNode->val << std::endl;
				pre = topNode;
				s.pop();
			}
		}
	}
}
void DepthFirstTravel(TreeNode *root)
{
	if (root == NULL)
		return;
	TreeNode *p = root;
	stack<TreeNode *> s;
	s.push(p);
	while (!s.empty())
	{
		p = s.top();
		std::cout << p->val << std::endl;
		s.pop();

		if (p->left)
			s.push(p->left);
		if (p->right)
			s.push(p->right);
	}
}
void BreadthFirstTravel(TreeNode *root)
{
	if (root == NULL)
		return;
	TreeNode *p = root;
	queue<TreeNode *> q;
	q.push(p);
	while (!q.empty())
	{
		p = q.front();
		std::cout << p->val << std::endl;
		q.pop();

		if (p->left)
			q.push(p->left);
		if (p->right)
			q.push(p->right);
	}
}
void noRePostOrder1(TreeNode *root) //Iterative solution using stack
{
	stack<TreeNode *> toVisit;
	TreeNode *curNode = root;
	TreeNode *lastNode = nullptr;
	while (!toVisit.empty() || curNode != nullptr)
	{
		if (curNode != nullptr)
		{
			toVisit.push(curNode);
			curNode = curNode->left;
		}
		else
		{
			TreeNode *topNode = toVisit.top();
			if (topNode->right != nullptr && lastNode != topNode->right)
			{
				curNode = topNode->right;
			}
			else
			{
				cout << topNode->val;
				lastNode = topNode;
				toVisit.pop();
			}
		}
	}
}
