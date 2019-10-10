//
// Created by Wang on 2019/10/13.
//

#include "Leetcode167cn.h"

vector<int> Leetcode167cn::twoSum(vector<int> &numbers, int target) {
    int low = 1;
    int high = numbers.size();
    while (low < high) {
        int sum = numbers[low - 1] + numbers[high - 1];
        if (sum == target) {
            return vector<int>{low, high};
        }
        if (sum > target) {
            --high;
        } else {
            ++low;
        }
    }
    return vector<int>{0, 0};
}
