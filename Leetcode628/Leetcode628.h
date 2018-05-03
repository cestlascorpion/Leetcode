//
// Created by cestl on 2018/5/3 0003.
//

#ifndef LEETCODE_LEETCODE628_H
#define LEETCODE_LEETCODE628_H

#include "../config.h"

class Leetcode628 {
public:
    int maximumProduct(vector<int> &nums) {
        int ans = 1;
        sort(nums.begin(), nums.end());
        if (nums[0] >= 0 || nums[nums.size() - 1] <= 0)
            return nums[nums.size() - 1] * nums[nums.size() - 2] * nums[nums.size() - 3];

        int t1 = INT32_MIN;
        if (nums[nums.size() - 3] >= 0)
            t1 = nums[nums.size() - 1] * nums[nums.size() - 2] * nums[nums.size() - 3];
        int t2 = INT32_MIN;
        if (nums[1] <= 0)
            t2 = nums[0] * nums[1] * nums[nums.size() - 1];
        return max(t1, t2);

    }
};


#endif //LEETCODE_LEETCODE628_H
