//
// Created by cestl on 2018/4/29 0029.
//

#include "Leetcode27.h"

int Leetcode27::removeElement(vector<int> &nums, int val) {
    int low = 0;
    int high = nums.size() - 1;
    while (low < high) {
        while (low < high && nums[low] != val)
            ++low;
        while (low < high && nums[high] == val)
            --high;
        swap(nums[low], nums[high]);
    }
    if (low == nums.size() - 1 && nums[low] != val)
        return nums.size();
    return low;
}
