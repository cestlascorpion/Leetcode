//
// Created by Wang on 2019/11/30.
//

#ifndef LEETCODE_LEETCODE590CN_H
#define LEETCODE_LEETCODE590CN_H

#include "config.h"

class Leetcode590cn {
public:
    vector<int> postorder(Node* root);
    vector<int> postorder2(Node* root);

private:
    void helper(Node *root, vector<int> &res);
};

#endif // LEETCODE_LEETCODE590CN_H
