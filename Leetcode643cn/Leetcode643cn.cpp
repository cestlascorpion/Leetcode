//
// Created by Wang on 2019/10/20.
//

#include "Leetcode643cn.h"

double Leetcode643cn::findMaxAverage(vector<int> &nums, int k) {
    if (nums.size() < k) {
        return 0.0;
    }
    auto sum = 0.0;
    for (int i = 0; i < k; ++i) {
        sum += nums[i];
    }
    auto max = sum;
    for (int i = k; i < nums.size(); ++i) {
        sum += nums[i] - nums[i - k];
        max = std::max(max, sum);
    }
    return max / (double)k;
}
