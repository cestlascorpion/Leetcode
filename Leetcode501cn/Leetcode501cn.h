//
// Created by Wang on 2019/11/28.
//

#ifndef LEETCODE_LEETCODE501CN_H
#define LEETCODE_LEETCODE501CN_H

#include "config.h"

class Leetcode501cn {
    vector<int> findMode(TreeNode *root);

    vector<int> findMode2(TreeNode *root);

private:
    void helper(TreeNode *cur, TreeNode *&pre, int &cnt, int &max, vector<int> &ans);
};

#endif // LEETCODE_LEETCODE501CN_H
