//
// Created by cestl on 2018/4/29 0029.
//

#ifndef LEETCODE_LEETCODE337_H
#define LEETCODE_LEETCODE337_H

#include "../config.h"

class Leetcode337 {
public:
    int rob(TreeNode *root);

    int rob2(TreeNode *root);

private:
    int tryRob(TreeNode *root, int &l, int &r);

    pair<int, int> tryrob2(TreeNode *root);
};


#endif //LEETCODE_LEETCODE337_H
