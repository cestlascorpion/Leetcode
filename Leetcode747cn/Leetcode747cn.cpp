//
// Created by Wang on 2019/12/2.
//

#include "Leetcode747cn.h"

int Leetcode747cn::dominantIndex(vector<int> &nums) {
    int res = -1;
    if (nums.empty()) {
        return -1;
    }
    int max = nums[0];
    for (int i = 0; i < nums.size(); ++i) {
        if (max < nums[i]) {
            max = nums[i];
            res = i;
        }
    }
    for (const auto &num : nums) {
        if (max != num) {
            if (num * 2 > max) {
                return -1;
            }
        }
    }
    return res;
}
