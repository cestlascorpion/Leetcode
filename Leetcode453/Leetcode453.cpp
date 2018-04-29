//
// Created by cestl on 2018/4/29 0029.
//

#include "Leetcode453.h"

int Leetcode453::minMoves(vector<int> &nums) {
    int mn = INT32_MAX, res = 0;
    for (int num : nums)
        mn = min(mn, num);
    for (int num : nums)
        res += num - mn;
    return res;
}
