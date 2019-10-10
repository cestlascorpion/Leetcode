//
// Created by Wang on 2019/10/14.
//

#include "Leetcode16cn.h"

int Leetcode16cn::threeSumClosest(vector<int> &nums, int target) {
    sort(nums.begin(), nums.end());

    int res = nums[0] + nums[1] + nums[2];
    for (int i = 0; i < nums.size() - 2; ++i) {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        int lo = i + 1;
        int hi = nums.size() - 1;

        while (lo < hi) {
            int sum = nums[i] + nums[lo] + nums[hi];
            if (sum == target) {
                return 0;
            }

            if (abs(sum - target) < abs(res - target)) {
                res = sum;
            }
            if (sum > target) {
                --hi;
            } else {
                ++lo;
            }
        }
    }
    return res;
}
