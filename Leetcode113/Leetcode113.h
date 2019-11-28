//
// Created by cestl on 2018/4/29 0029.
//

#ifndef LEETCODE_LEETCODE113_H
#define LEETCODE_LEETCODE113_H

#include "config.h"

class Leetcode113 {
public:
    vector<vector<int>> pathSum(TreeNode *root, int sum);

private:
    void helper(TreeNode *root, int sum, int cur,
                vector<int> &path, vector<vector<int>> &ans);
};


#endif //LEETCODE_LEETCODE113_H
