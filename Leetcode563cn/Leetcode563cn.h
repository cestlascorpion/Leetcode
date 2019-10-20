//
// Created by Wang on 2019/10/20.
//

#ifndef LEETCODE_LEETCODE563CN_H
#define LEETCODE_LEETCODE563CN_H

#include <config.h>

class Leetcode563cn {
public:
    int findTilt(TreeNode *root);
    int helper(TreeNode *root, int &tilt);
};

#endif // LEETCODE_LEETCODE563CN_H
