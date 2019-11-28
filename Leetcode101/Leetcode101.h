//
// Created by hans on 4/26/18.
//

#ifndef LEETCODE_LEETCODE101_H
#define LEETCODE_LEETCODE101_H

#include "config.h"

class Leetcode101 {
public:
    bool isSymmetric(TreeNode *root);

    void test101();

private:
    bool isSametree(TreeNode *l, TreeNode *r);
};


#endif //LEETCODE_LEETCODE101_H
