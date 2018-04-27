//
// Created by hans on 4/27/18.
//

#include "Leetcode53.h"

int Leetcode53::maxSubArray(vector<int> &nums) {
    if (nums.empty())
        return 0;
    int ans = INT32_MIN;
    int cur = 0;
    // nums[0：i]的maxSubArray必须具有nums[i]作为结束元素
    // maxSubArray(nums, i) =
    // max(nums[i]+maxSubArray(nums, i-1)+nums[i]);
    for (auto item : nums) {
        cur = max(item, cur + item);
        ans = max(ans, cur);
    }
    return ans;
}

int Leetcode53::maxSubArray2(vector<int> &nums) {
    if (nums.empty())
        return 0;
    return helper(nums, 0, static_cast<int>(nums.size() - 1));
}

int Leetcode53::helper(vector<int> &nums, int low, int high) {
    if (low >= high)
        return nums[low];

    int mid = low + (high - low) / 2;
    int lmax = helper(nums, low, mid - 1);
    int rmax = helper(nums, mid + 1, high);
    int mmax = nums[mid], t = mmax;
    for (int i = mid - 1; i >= low; --i) {
        t += nums[i];
        mmax = max(mmax, t);
    }
    t = mmax;
    for (int i = mid + 1; i <= high; ++i) {
        t += nums[i];
        mmax = max(mmax, t);
    }
    return max(mmax, max(lmax, rmax));
}

void Leetcode53::test53() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "max SubArray -> " << maxSubArray(nums) << endl;
    cout << "max SubArray -> " << maxSubArray2(nums) << endl;

}
