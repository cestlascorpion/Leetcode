//
// Created by cestl on 2018/4/29 0029.
//

#ifndef LEETCODE_LEETCODE437_H
#define LEETCODE_LEETCODE437_H

#include "config.h"

class leetcode437 {
public:
    int pathSum(TreeNode *root, int sum);

    int helper(TreeNode *node, int sum);//path from this node

    int pathSum2(TreeNode *root, int sum);

    int helper2(TreeNode *root, int pre, int &sum);
};


#endif //LEETCODE_LEETCODE437_H
