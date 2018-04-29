//
// Created by cestl on 2018/4/29 0029.
//

#include "Leetcode169.h"

int Leetcode169::majorityElement(vector<int> &nums) {
    int count = 0;
    int ans;
    for (int i = 0; i < nums.size(); i++) {
        if (count == 0)
            ans = nums[i];
        count += (nums[i] == ans ? 1 : -1);
    }
    return ans;
}
