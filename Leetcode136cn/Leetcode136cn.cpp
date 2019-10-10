//
// Created by Wang on 2019/10/13.
//

#include "Leetcode136cn.h"

int Leetcode136cn::singleNumber(vector<int> &nums) {
    int res = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
        res ^= nums[i];
    }
    return res;
}
