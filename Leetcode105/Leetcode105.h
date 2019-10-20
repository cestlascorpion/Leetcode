//
// Created by cestl on 2018/4/28 0028.
//

#ifndef LEETCODE_LEETCODE105_H
#define LEETCODE_LEETCODE105_H

#include <config.h>

class Leetcode105 {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder);

    TreeNode *buildTree2(vector<int> &preorder, vector<int> &inorder);

private:
    TreeNode *dfs(vector<int> &preorder, vector<int> &inorder, int pl, int pr, int il, int ir);
};


#endif //LEETCODE_LEETCODE105_H
