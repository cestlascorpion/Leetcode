//
// Created by cestl on 2018/5/3 0003.
//

#include "Leetcode724.h"

int Leetcode724::pivotIndex(vector<int> &nums) {
    int iSum = accumulate(nums.begin(), nums.end(), 0);
    int iCur = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if ((iSum - nums[i]) == 2 * iCur)
            return i;
        iCur += nums[i];
    }
    return -1;
}
