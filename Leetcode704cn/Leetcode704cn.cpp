//
// Created by Wang on 2019/10/20.
//

#include "Leetcode704cn.h"

int Leetcode704cn::search(vector<int> &nums, int target) {
    auto iter = lower_bound(nums.begin(), nums.end(), target);
    if (iter == nums.end() || *iter != target) {
        return -1;
    } else {
        return distance(nums.begin(), iter);
    }
}
