//
// Created by cestl on 2018/5/2 0002.
//

#ifndef LEETCODE_LEETCODE494_H
#define LEETCODE_LEETCODE494_H

#include "config.h"

class Leetcode494 {
public:
    int findTargetSumWays(vector<int> &nums, int S);

    int findTargetSumWays2(vector<int> &nums, int S);

    void helper2(vector<int> &nums, int target, int cur, int begin, int end, int &ans);

    int findTargetSumWays3(vector<int> &nums, int S);

    void helper3(vector<int> &nums, const int &S, int cur, int begin, int end, int &ans);
};


#endif //LEETCODE_LEETCODE494_H
