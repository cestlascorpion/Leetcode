//
// Created by cestl on 2018/4/29 0029.
//

#include "Leetcode238.h"

vector<int> Leetcode238::productExceptSelf(vector<int> &nums) {
    int n = nums.size();;
    int forward = 1;
    int backward = 1;
    vector<int> ans(n, 1);
    for (int i = 0; i < n; ++i) {
        ans[i] = ans[i] * forward;
        forward = forward * nums[i];
        ans[n - 1 - i] = ans[n - 1 - i] * backward;
        backward = backward * nums[n - 1 - i];
    }
    return ans;
}
