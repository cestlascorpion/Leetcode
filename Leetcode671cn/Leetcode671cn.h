//
// Created by Wang on 2019/12/2.
//

#ifndef LEETCODE_LEETCODE671CN_H
#define LEETCODE_LEETCODE671CN_H

#include "config.h"

class Leetcode671cn {
public:
    int findSecondMinimumValue(TreeNode *root);

private:
    int helper(TreeNode *node, int min);
};

#endif // LEETCODE_LEETCODE671CN_H
