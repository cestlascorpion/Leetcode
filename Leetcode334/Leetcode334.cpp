//
// Created by cestl on 2018/4/28 0028.
//

#include "Leetcode334.h"

bool Leetcode334::increasingTriplet(vector<int> &nums) {
    if (nums.size() < 3)
        return false;

    int min = INT32_MAX;
    int m2n = INT32_MAX;

    for (auto item : nums) {
        if (min >= item)
            min = item;
        else if (m2n >= item)
            m2n = item;
        else
            return  true;
    }
    return false;
}
