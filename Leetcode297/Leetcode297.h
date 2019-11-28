//
// Created by cestl on 2018/5/4 0004.
//

#ifndef LEETCODE_LEETOCDE297_H
#define LEETCODE_LEETOCDE297_H

#include "config.h"

class Leetcode297 {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root);

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data);

    void test297();

private:
    void serializeHelper(TreeNode *root, string &ans);

    list<string> deserializeSplit(string &data);

    TreeNode *deserializeHelper(list<string> &str);
};

#endif //LEETCODE_LEETOCDE297_H
