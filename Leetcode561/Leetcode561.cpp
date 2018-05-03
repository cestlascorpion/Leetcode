//
// Created by cestl on 2018/5/3 0003.
//

#include "Leetcode561.h"

int Leetcode561::arrayPairSum(vector<int> &nums) {
    if (nums.empty()) {
        return 0;
    }
    sort(nums.begin(), nums.end());
    int sum = 0;
    //计算两两一组中，数小的那个，和即为结果
    for (int i = 0; i < nums.size(); i += 2) {
        sum += nums[i];
    }
    return sum;
}
