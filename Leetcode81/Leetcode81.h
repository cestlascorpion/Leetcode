//
// Created by cestl on 2018/5/3 0003.
//

#ifndef LEETCODE_LEETCODE81_H
#define LEETCODE_LEETCODE81_H

#include "config.h"

class Leetcode81 {
public:
    int search(vector<int> &nums, int target);

    void test81();

private:
    int binarySearch(vector<int> &nums, int low, int high, int target);
};


#endif //LEETCODE_LEETCODE81_H
