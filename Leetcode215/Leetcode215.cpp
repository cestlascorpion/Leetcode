//
// Created by cestl on 2018/5/3 0003.
//

#include "Leetcode215.h"

int Leetcode215::findKthLargest(vector<int> &nums, int k) {
    int low = 0;
    int high = nums.size() - 1;
    int ans = 0;
    while (low <= high) {
        int p = partion(nums, low, high);
        if (p == k - 1) {
            ans = p;
            break;
        } else if (p < k - 1) {
            low = p + 1;
        } else {
            high = p - 1;
        }
    }
    return nums[ans];
}

int Leetcode215::partion(vector<int> &nums, int low, int high) {
    int key = nums[low];
    while (low < high) {
        while (low < high && nums[high] < key)
            --high;
        nums[low] = nums[high];
        while (low < high && nums[low] >= key)
            ++low;
        nums[high] = nums[low];
    }
    nums[low] = key;
    return low;
}

void Leetcode215::test215() {
    vector<int> nums = {3, 2};
    cout << findKthLargest(nums, 2) << endl;
}

int Leetcode215::findKthLargest2(vector<int> &nums, int k) {
    sort(nums.begin(), nums.end());
    return nums[nums.size() - k];
}
