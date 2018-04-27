//
// Created by hans on 4/26/18.
//

#ifndef LEETCODE_LEETCODE255_H
#define LEETCODE_LEETCODE255_H

#include "../config.h"

class Leetcode255 {
public:
    bool isValidBST(TreeNode *root);

    bool isValidBST2(TreeNode *root);

    bool isValidBST3(TreeNode *root);

    void test255();

private:
    bool helper2(TreeNode *root, long maxV, long minV);

    bool helper3(TreeNode *root, long &pre);
};


#endif //LEETCODE_LEETCODE255_H
