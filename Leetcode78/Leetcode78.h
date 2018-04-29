//
// Created by hans on 4/29/18.
//

#ifndef LEETCODE_LEETCODE78_H
#define LEETCODE_LEETCODE78_H

#include "../config.h"

class Leetcode78 {
public:
    vector<vector<int>> subsets(vector<int> &nums);

private:
    void helper(vector<int> &curset, int begin, int end, vector<int> &nums, vector<vector<int>> &ans);
};


#endif //LEETCODE_LEETCODE78_H
