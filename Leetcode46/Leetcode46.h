//
// Created by hans on 4/29/18.
//

#ifndef LEETCODE_LEETCODE46_H
#define LEETCODE_LEETCODE46_H

#include "../config.h"

class Leetcode46 {
public:
    vector<vector<int>> permute(vector<int> &nums);

    vector<vector<int>> permute2(vector<int> &nums);

    void test46();

private:
    void helper(vector<int> nums, int begin, int end, vector<vector<int>> &ans);
};


#endif //LEETCODE_LEETCODE46_H
