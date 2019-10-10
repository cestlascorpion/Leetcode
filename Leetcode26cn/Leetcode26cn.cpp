//
// Created by Wang on 2019/10/13.
//

#include "Leetcode26cn.h"

int Leetcode26cn::removeDuplicates(vector<int> &nums) {
    if (nums.empty())
        return 0;

    int ptr = 0;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[ptr] != nums[i]) {
            ++ptr;
            nums[ptr] = nums[i];
        }
    }
    return ptr+1;
}
