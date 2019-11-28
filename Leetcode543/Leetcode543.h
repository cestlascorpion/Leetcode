//
// Created by cestl on 2018/5/3 0003.
//

#ifndef LEETCODE_LEETCODE543_H
#define LEETCODE_LEETCODE543_H

#include "config.h"

class Leetcode543 {
public:
    int diameterOfBinaryTree(TreeNode *root);
    int diameterOfBinaryTree2(TreeNode *root);

private:
    int helper(TreeNode *root);
    int helper2(TreeNode *root,int &ans);
};


#endif //LEETCODE_LEETCODE543_H
