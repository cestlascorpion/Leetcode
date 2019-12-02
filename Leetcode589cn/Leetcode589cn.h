//
// Created by Wang on 2019/11/30.
//

#ifndef LEETCODE_LEETCODE589CN_H
#define LEETCODE_LEETCODE589CN_H

#include "config.h"

class Leetcode589cn {
public:
    vector<int> preorder(Node* root);
    vector<int> preorder2(Node* root);

private:
    void helper(Node *root, vector<int> &ans);
};

#endif // LEETCODE_LEETCODE589CN_H
