//
// Created by hans on 18-4-23.
//

#ifndef LEETCODE_BINARYTREE_H
#define LEETCODE_BINARYTREE_H

#include <config.h>

using namespace std;

class BinaryTree {
public:
    //root->left->right
    vector<int> rePreorder(TreeNode *root);

    //left->root->right
    vector<int> reInorder(TreeNode *root);

    //left->right->root
    vector<int> rePostorder(TreeNode *root);

    //left->right->root
    vector<int> rePostorder2(TreeNode *root);

    //root->left->right
    vector<int> Preorder(TreeNode *root);

    //left->root->right
    vector<int> Inorder(TreeNode *root);

    //left->right->root
    vector<int> Postorder(TreeNode *root);

    //left->right->root
    // reverse the order
    // (root->"left"->"right")
    // to
    //("right"->"left"->root)
    //take "right" as left and "left" as "right"
    vector<int> Postorder2(TreeNode *root);

    //Breadth First Travel
    vector<int> BFS(TreeNode *root);

    //test all the algorithms
    void testBinaryTree();

private:
    void rePreorderHelper(TreeNode *root, vector<int> &ans);

    void reInorderHelper(TreeNode *root, vector<int> &ans);

    void rePostorderHelper(TreeNode *root, vector<int> &ans);

    void rePostorderHelper2(TreeNode *root, vector<int> &ans);

};


#endif //LEETCODE_BINARYTREE_H
