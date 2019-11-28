//
// Created by Wang on 2019/11/27.
//

#ifndef LEETCODE_LEETCODE404CN_H
#define LEETCODE_LEETCODE404CN_H

#include "config.h"

class Leetcode404cn {
public:
    int sumOfLeftLeaves(TreeNode* root);

    int helper(TreeNode* root, bool l);
};


#endif //LEETCODE_LEETCODE404CN_H
