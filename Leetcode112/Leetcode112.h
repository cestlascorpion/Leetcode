//
// Created by cestl on 2018/4/29 0029.
//

#ifndef LEETCODE_LEETCODE112_H
#define LEETCODE_LEETCODE112_H

#include <config.h>

class Leetcode112 {
public:
    bool hasPathSum(TreeNode *root, int sum);

private:
    void helper(TreeNode *root, int sum, int cur, bool &ans);
};


#endif //LEETCODE_LEETCODE112_H
