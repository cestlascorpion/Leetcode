//
// Created by cestl on 2018/5/3 0003.
//

#ifndef LEETCODE_LEETCODE606_H
#define LEETCODE_LEETCODE606_H

#include "config.h"

class Leetcode606 {
public:
    string tree2str(TreeNode *t) {
        string ans;
        if (t == nullptr)
            return ans;
        if (t->left == nullptr && t->right == nullptr) {
            return to_string(t->val);
        }
        if (t->left == nullptr) {
            return to_string(t->val) + "()" + "(" + tree2str(t->right) + ")";
        }
        if (t->right == nullptr) {
            return to_string(t->val) + "(" + tree2str(t->left) + ")";
        }
        return to_string(t->val) + "(" + tree2str(t->left) + ")" + "(" + tree2str(t->right) + ")";
    }
};


#endif //LEETCODE_LEETCODE606_H
