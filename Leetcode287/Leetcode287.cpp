//
// Created by cestl on 2018/4/29 0029.
//

#include "Leetcode287.h"

int Leetcode287::findDuplicate(vector<int> &nums) {
    int ans = nums[0];
    for (int i = 1; i < nums.size(); ++i)
        ans = ans ^ nums[i];
    return ans;
}
