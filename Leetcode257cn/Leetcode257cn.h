//
// Created by Wang on 2019/10/13.
//

#ifndef LEETCODE_LEETCODE257CN_H
#define LEETCODE_LEETCODE257CN_H

#include <config.h>

class Leetcode257cn {
public:
    vector<string> binaryTreePaths(TreeNode *root);

    void DFS(TreeNode *root, string path, vector<string> &res);
};


#endif //LEETCODE_LEETCODE257CN_H
