//
// Created by cestl on 2018/5/3 0003.
//

#ifndef LEETCODE_LEETCODE572_H
#define LEETCODE_LEETCODE572_H

#include <config.h>

class Leetcode572 {
public:
    bool isSubtree(TreeNode *s, TreeNode *t);

private:
    bool isSametree(TreeNode *s, TreeNode *t);
};


#endif //LEETCODE_LEETCODE572_H
