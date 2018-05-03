//
// Created by cestl on 2018/5/3 0003.
//

#include "Leetcode55.h"

bool Leetcode55::canJump(vector<int> &nums) {
    if (nums.empty())
        return false;
    int end = nums.size() - 1;
    int maxlength = nums[0];
    //最远可以到达的地点
    for (int i = 0; i <= maxlength; ++i) {
        if (nums[i] + i > maxlength)
            maxlength = nums[i] + i;
        if (maxlength >= end)
            return true;
    }
    return false;
}

void Leetcode55::test55() {
    vector<int> nums;
    nums = {2, 3, 1, 1, 4};
    cout << canJump(nums) << "==true?" << endl;
    nums = {3, 2, 1, 0, 4};
    cout << canJump(nums) << "==false?" << endl;
}
