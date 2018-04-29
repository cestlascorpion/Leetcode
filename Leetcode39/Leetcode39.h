//
// Created by cestl on 2018/4/29 0029.
//

#ifndef LEETCODE_LEETCODE39_H
#define LEETCODE_LEETCODE39_H

#include "../config.h"

class Leetcode39 {
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target);

private:
    void helper(vector<int> &candidates, vector<int> &res, int begin, int target, vector<vector<int>> &ans);
};


#endif //LEETCODE_LEETCODE39_H
