//
// Created by Wang on 2019/10/13.
//

#include "Leetcode53cn.h"

int Leetcode53cn::maxSubArray(vector<int> &nums) {
    if (nums.empty()) return 0;

    int max = nums[0];
    int res = max;
    for (int i = 1; i < nums.size(); ++i) {
        max = std::max(nums[i], max + nums[i]);
        res = std::max(max, res);
    }
    return res;
}
