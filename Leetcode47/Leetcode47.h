//
// Created by cestl on 2018/4/29 0029.
//

#ifndef LEETCODE_LEETCODE47_H
#define LEETCODE_LEETCODE47_H

#include "config.h"

class Leetcode47 {
public:
    vector<vector<int>> permuteUnique(vector<int> &nums);

    void test47();

private:
    void helper(vector<int> nums, int begin, vector<vector<int>> &ans);
    void helper2(vector<int> &nums, int begin, vector<vector<int>> &ans);
};


#endif //LEETCODE_LEETCODE47_H
