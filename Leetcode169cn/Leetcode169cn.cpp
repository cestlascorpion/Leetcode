//
// Created by Wang on 2019/10/13.
//

#include "Leetcode169cn.h"

int Leetcode169cn::majorityElement(vector<int> &nums) {
    int res = nums[0];
    int cnt = 1;
    for (int i = 1; i < nums.size(); ++i) {
        if (res == nums[i]) {
            ++cnt;
        } else {
            --cnt;
            if (cnt == -1) {
                res = nums[i];
                cnt = 1;
            }
        }
    }
    return res;
}
