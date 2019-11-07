//
// Created by Wang on 2019/11/7.
//

#include "Leetcode1228cn.h"

int Leetcode1228cn::missingNumber(vector<int> &arr) {
    int delta = (arr[arr.size() - 1] - arr[0]) / (int)arr.size();

    for (uint64_t i = 1; i < arr.size(); ++i) {
        if (arr[i] != arr[i - 1] + delta) {
            return arr[i - 1] + delta;
        }
    }
    return -1;
}
