//
// Created by cestl on 2018/5/14 0014.
//

#ifndef LEETCODE_LEETCODE98_H
#define LEETCODE_LEETCODE98_H

#include "config.h"

class LeetCode98 {
public:
    bool isValidBST(TreeNode *root);

    bool helper(TreeNode *root, int &min_val, int &max_val);
};


#endif //LEETCODE_LEETCODE98_H
