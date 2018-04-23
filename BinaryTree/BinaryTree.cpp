//
// Created by hans on 18-4-23.
//

#include "BinaryTree.h"

vector<int> BinaryTree::rePreorder(TreeNode *root) {
    vector<int> ans;
    if (root == nullptr)
        return ans;
    rePreorderHelper(root, ans);
    return ans;
}

vector<int> BinaryTree::reInorder(TreeNode *root) {
    vector<int> ans;
    if (root == nullptr)
        return ans;
    reInorderHelper(root, ans);
    return ans;
}

vector<int> BinaryTree::rePostorder(TreeNode *root) {
    vector<int> ans;
    if (root == nullptr)
        return ans;
    rePostorderHelper(root, ans);
    return ans;
}

vector<int> BinaryTree::rePostorder2(TreeNode *root) {
    vector<int> ans;
    if (root == nullptr)
        return ans;
    rePostorderHelper2(root, ans);
    reverse(ans.begin(), ans.end());
    return ans;
};

vector<int> BinaryTree::Preorder(TreeNode *root) {
    vector<int> ans;
    if (root == nullptr)
        return ans;
    stack<TreeNode *> s;
    TreeNode *p = root;
    while (s.empty() == false || p != nullptr) {
        if (p != nullptr) {
            ans.push_back(p->val);
            s.push(p);
            p = p->left;
        } else {
            p = s.top();
            s.pop();
            p = p->right;
        }
    }
    return ans;
}

vector<int> BinaryTree::Inorder(TreeNode *root) {
    vector<int> ans;
    if (root == nullptr)
        return ans;
    stack<TreeNode *> s;
    TreeNode *p = root;
    while (s.empty() == false || p != nullptr) {
        if (p != nullptr) {
            s.push(p);
            p = p->left;
        } else {
            p = s.top();
            s.pop();
            ans.push_back(p->val);
            p = p->right;
        }
    }
    return ans;
}

vector<int> BinaryTree::Postorder(TreeNode *root) {
    vector<int> ans;
    if (root == nullptr)
        return ans;
    stack<TreeNode *> s;
    TreeNode *cur = root;
    TreeNode *pre = nullptr;
    while (s.empty() == false || cur != nullptr) {
        if (cur != nullptr) {
            s.push(cur);
            cur = cur->left;
        } else {
            TreeNode *t = s.top();
            if (t->right != nullptr && t->right != pre) {
                cur = t->right;
            } else {
                ans.push_back(t->val);
                pre = t;
                s.pop();
            }
        }
    }
    return ans;
}

vector<int> BinaryTree::Postorder2(TreeNode *root) {
    vector<int> ans;
    if (root == nullptr)
        return ans;
    stack<TreeNode *> s;
    TreeNode *p = root;
    while (s.empty() == false || p != nullptr) {
        if (p != nullptr) {
            ans.push_back(p->val);
            s.push(p);
            p = p->right;
        } else {
            p = s.top();
            s.pop();
            p = p->left;
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

vector<int> BinaryTree::BFS(TreeNode *root) {
    vector<int> ans;
    if (root == nullptr)
        return ans;
    queue<TreeNode *> q;
    TreeNode *p = root;
    q.push(p);
    while (!q.empty()) {
        p = q.front();
        ans.push_back(p->val);
        q.pop();
        if (p->left)
            q.push(p->left);
        if (p->right)
            q.push(p->right);
    }
    return ans;
}

void BinaryTree::testBinaryTree() {
    TreeNode p0(0);
    TreeNode p1(1);
    TreeNode p2(2);
    TreeNode p3(3);
    TreeNode p4(4);
    TreeNode p5(5);
    TreeNode p6(6);
    TreeNode *p = &p0;
    p0.left = &p1;
    p0.right = &p2;

    p1.left = &p3;
    p1.right = &p4;

    p2.left = &p5;
    p2.right = &p6;

    vector<int> ans;
    vector<int> res;

    res = {0, 1, 3, 4, 2, 5, 6};
    ans = rePreorder(p);
    if (ans == res)
        cout << "rePreorder tested with no bugs." << endl;
    else
        cout << "rePreorder tested failed." << endl;
    ans = Preorder(p);
    if (ans == res)
        cout << "Preorder tested with no bugs." << endl;
    else
        cout << "Preorder tested failed." << endl;

    res = {3, 1, 4, 0, 5, 2, 6};
    ans = reInorder(p);
    if (ans == res)
        cout << "reInorder tested with no bugs." << endl;
    else
        cout << "reInorder tested failed." << endl;
    ans = Inorder(p);
    if (ans == res)
        cout << "Inorder tested with no bugs." << endl;
    else
        cout << "Inorder tested failed." << endl;

    res = {3, 4, 1, 5, 6, 2, 0};
    ans = rePostorder(p);
    if (ans == res)
        cout << "rePostorder tested with no bugs." << endl;
    else
        cout << "rePostorder tested failed." << endl;
    ans = Postorder(p);
    if (ans == res)
        cout << "Postorder tested with no bugs." << endl;
    else
        cout << "Postorder tested failed." << endl;
    ans = rePostorder2(p);
    if (ans == res)
        cout << "rePostorder2 tested with no bugs." << endl;
    else
        cout << "rePostorder2 tested failed." << endl;
    ans = Postorder2(p);
    if (ans == res)
        cout << "Postorder2 tested with no bugs." << endl;
    else
        cout << "Postorder2 tested failed." << endl;

    res = {0, 1, 2, 3, 4, 5, 6};
    ans = BFS(p);
    if (ans == res)
        cout << "BFS tested with no bugs." << endl;
    else
        cout << "BFS tested failed." << endl;
}