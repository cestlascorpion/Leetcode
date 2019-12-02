//
// Created by Wang on 2019/12/2.
//

#include "Leetcode674cn.h"

int Leetcode674cn::findLengthOfLCIS(vector<int> &nums) {
    if (nums.empty()) {
        return 0;
    }
    int res = 1;
    int len = 1;
    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] > nums[i - 1]) {
            ++len;
        } else {
            res = max(res, len);
            len = 1;
        }
    }
    return res;
}
