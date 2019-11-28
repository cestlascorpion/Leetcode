//
// Created by cestl on 2018/5/3 0003.
//

#ifndef LEETCODE_LEETCODE653_H
#define LEETCODE_LEETCODE653_H

#include "config.h"

class Leetcode653 {
public:
    bool findTarget(TreeNode *root, int k);

    void preorder(const TreeNode *p, const TreeNode *r, const int k, bool &ans);

    bool find(const TreeNode *root, int k);
};


#endif //LEETCODE_LEETCODE653_H
