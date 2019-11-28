//
// Created by cestl on 2018/5/2 0002.
//

#ifndef LEETCODE_LEETCODE538_H
#define LEETCODE_LEETCODE538_H

#include "config.h"

class Leetcode538 {
public:
    TreeNode *convertBST(TreeNode *root);

    TreeNode *convertBST2(TreeNode *root);

private:
    void helper(TreeNode *root, int &sumkey);
};


#endif //LEETCODE_LEETCODE538_H
