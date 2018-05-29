//
// Created by hans on 18-5-29.
//

#include "Leetcode35.h"

int Leetcode35::searchInsert(vector<int> &nums, int target) {
    if (nums.empty())
        return 0;
    int low = 0;
    int high = nums.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

void Leetcode35::test35() {
    vector<int> nums{1, 2, 3, 3, 5, 6};
    cout << searchInsert(nums, 0) << endl;
    cout << searchInsert(nums, 1) << endl;
    cout << searchInsert(nums, 3) << endl;
    cout << searchInsert(nums, 4) << endl;
    cout << searchInsert(nums, 6) << endl;
    cout << searchInsert(nums, 7) << endl;

}
