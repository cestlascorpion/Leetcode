//
// Created by cestl on 2018/4/29 0029.
//

#ifndef LEETCODE_LEETCODE40_H
#define LEETCODE_LEETCODE40_H

#include <config.h>

class Leetcode40 {
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target);

private:
    void helper(vector<int> &candidates, vector<int> &res, int begin, int target, vector<vector<int>> &ans);
};


#endif //LEETCODE_LEETCODE40_H
