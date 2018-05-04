//
// Created by cestl on 2018/5/3 0003.
//

#include "Leetcode300.h"

int Leetcode300::lengthOfLIS(vector<int> &nums) {
    if (nums.empty())
        return false;
    vector<int> helper;
    // 因为要找increasing的序列，所以先遍历数组。
    // 再用二分法找当前值应该在排好序的数组中的插入位置。
    // 对于排好序的数组，尽量用较小的值去替换已经排好序的数组中的值。
    // 因为要找的是最长的序列，所以每次将排好序的数组中替换成
    // 已经排好序的，会能保证得到的结果是最长的。
    for (int i = 0; i < nums.size(); ++i) {
        int begin = 0;
        int end = helper.size();
        while (begin < end) {
            int mid = begin + (end - begin) / 2;
            if (helper[mid] < nums[i])
                begin = mid + 1;
            else
                end = mid;
        }
        if (end >= helper.size())
            helper.push_back(nums[i]);
        else
            helper[end] = nums[i];
    }
    return helper.size();
}

int Leetcode300::lengthOfLIS2(vector<int> &nums) {
    if (nums.empty())
        return false;
    // 以helper[i]结尾的位置所包括的升序序列的最大长度
    vector<int> helper(nums.size(), 1);
    int ans = 1;
    for (int i = 1; i < nums.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[j] < nums[i])
                // nums[i]能够和nums[j]的升序序列构成新的升序序列
                helper[i] = max(helper[i], helper[j] + 1);
        }
        ans = max(ans, helper[i]);
    }
    return ans;
}

void Leetcode300::test300() {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << lengthOfLIS(nums) << endl;
}
