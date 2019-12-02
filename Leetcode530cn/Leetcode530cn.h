//
// Created by Wang on 2019/11/29.
//

#ifndef LEETCODE_LEETCODE530CN_H
#define LEETCODE_LEETCODE530CN_H

#include "config.h"

class Leetcode530cn {
public:
    int getMinimumDifference(TreeNode* root);

    void helper(TreeNode *cur, TreeNode *&pre, int &min);
};

#endif // LEETCODE_LEETCODE530CN_H
