//
// Created by cestl on 2018/5/14 0014.
//

#include "Leetcode152.h"

int Leetcode152::maxProduct(vector<int> &nums) {
    if (nums.empty())
        return 0;
    int length = nums.size();
    //读取到index为i的最大序列存放在i+1的位置
    vector<int> maxArray(length + 1, 1);
    vector<int> minArray(length + 1, 1);
    for (int i = 1; i <= length; ++i) {
        maxArray[i] = max(nums[i - 1],
                          max(nums[i - 1] * maxArray[i - 1],
                              nums[i - 1] * minArray[i - 1]));
        //因为有负数，所以最小值可能变成最大值
        minArray[i] = min(nums[i - 1],
                          min(nums[i - 1] * maxArray[i - 1],
                              nums[i - 1] * minArray[i - 1]));
    }
    int ans = maxArray[1];
    for (int i = 1; i <= length; ++i) {
        ans = max(maxArray[i], ans);
    }
    return ans;
}
