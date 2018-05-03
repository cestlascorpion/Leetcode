//
// Created by cestl on 2018/5/3 0003.
//

#include "Leetcode34.h"

vector<int> Leetcode34::searchRange(vector<int> &nums, int target) {
    vector<int> ans = {-1, -1};
    if (nums.empty())
        return ans;
    if (nums[0] > target || nums[nums.size() - 1] < target)
        return ans;
    int low = binarySearchLow(nums, 0, nums.size() - 1, target);
    int high = binarySearchHigh(nums, 0, nums.size() - 1, target);
    if (low <= high && nums[low] == target && nums[high] == target) {
        ans[0] = low;
        ans[1] = high;
    }
    return ans;
}

int Leetcode34::binarySearchLow(vector<int> &nums, int begin, int end, int target) {
    while (begin < end) {
        int mid = begin + (end - begin) / 2;
        if (nums[mid] < target) {
            begin = mid + 1;
        } else if (nums[mid] > target)
            end = mid - 1;
        else {
            end = mid;
        }
    }
    return begin;
}

int Leetcode34::binarySearchHigh(vector<int> &nums, int begin, int end, int target) {
    while (begin < end) {
        int mid = end - (end - begin) / 2;
        if (nums[mid] > target) {
            end = mid - 1;
        } else if (nums[mid] < target)
            begin = mid + 1;
        else {
            begin = mid;
        }
    }
    return end;
}

void Leetcode34::test34() {
    vector<int> nums = {0, 0, 1, 1, 1, 4, 5, 5};
    vector<int> ans = searchRange(nums, 2);
    cout << ans[0] << "-" << ans[1] << endl;
}
