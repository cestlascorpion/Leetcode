//
// Created by cestl on 2018/5/13 0013.
//

#ifndef LEETCODE_LEETCODECOMBINATION_H
#define LEETCODE_LEETCODECOMBINATION_H

#include <config.h>

class LeetcodeCombination {
public:
    vector<vector<int>> Combination(vector<int> nums);

    void testCombination();

private:
    void helper(vector<int> &cur, int begin, int end, vector<int> &nums, vector<vector<int>> &ans);
};


#endif //LEETCODE_LEETCODECOMBINATION_H
