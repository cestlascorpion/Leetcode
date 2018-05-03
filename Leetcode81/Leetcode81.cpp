//
// Created by cestl on 2018/5/3 0003.
//

#include "Leetcode81.h"

int Leetcode81::search(vector<int> &nums, int target) {
    if (nums.empty())
        return -1;
    int low = 0;
    int high = nums.size() - 1;
    if (nums[low] < nums[high])
        return binarySearch(nums, low, high, target);

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target)
            return mid;

        if (nums[mid] >= nums[low]) {
            if (target >= nums[low] && target < nums[mid]) {
                return binarySearch(nums, low, mid - 1, target);
            } else {
                low = mid + 1;
            }
            continue;
        }

        if (nums[mid] <= nums[high]) {
            if (target > nums[mid] && target <= nums[high]) {
                return binarySearch(nums, mid + 1, high, target);
            } else {
                high = mid - 1;
            }
            continue;
        }
    }
    return -1;
}

int Leetcode81::binarySearch(vector<int> &nums, int low, int high, int target) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

void Leetcode81::test81() {
    vector<int> nums;
    nums = {1, 3, 4, 5, 6, 7, 9};
    cout << search(nums, 6) << endl;
    nums = {6, 8, 9, 1, 2, 3, 4};
    cout << search(nums, 3) << endl;
    nums = {6, 8, 9, 1, 2, 3, 4};
    cout << search(nums, 8) << endl;
}
