//
// Created by hans on 4/27/18.
//

#ifndef LEETCODE_LEETCODE53_H
#define LEETCODE_LEETCODE53_H

#include "config.h"

class Leetcode53 {
public:
    int maxSubArray(vector<int> &nums);

    int maxSubArray2(vector<int> &nums);

    void test53();

private:
    int helper(vector<int> &nums, int low, int high);
};


#endif //LEETCODE_LEETCODE53_H
