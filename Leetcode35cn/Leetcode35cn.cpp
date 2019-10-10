//
// Created by Wang on 2019/10/13.
//

#include "Leetcode35cn.h"

int Leetcode35cn::searchInsert(vector<int> &nums, int target) {
    int res = 0;
    if (nums.empty()) return res;

    int lo = 0;
    int hi = nums.size() - 1;
    while (lo <= hi) {
        int mi = lo + (hi - lo) / 2;
        if (nums[mi] == target) {
            return mi;
        }
        if (nums[mi] > target) {
            hi = mi - 1;
        } else {
            lo = mi + 1;
        }
    }
    return lo;
}
