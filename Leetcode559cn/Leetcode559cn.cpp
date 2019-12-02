//
// Created by Wang on 2019/11/30.
//

#include "Leetcode559cn.h"

int Leetcode559cn::maxDepth(Node *root) {
    if (root == nullptr) {
        return 0;
    }
    int depth = 0;
    for (const auto &node : root->children) {
        depth = max(depth, maxDepth(node));
    }
    return depth + 1;
}
