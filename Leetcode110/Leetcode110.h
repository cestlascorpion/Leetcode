//
// Created by cestl on 2018/5/14 0014.
//

#ifndef LEETCODE_LEETCODE110_H
#define LEETCODE_LEETCODE110_H

#include <config.h>

class Leetcode110 {
public:
    bool isBalanced(TreeNode *root);

    bool helper(TreeNode *root, int& depth);
};


#endif //LEETCODE_LEETCODE110_H
