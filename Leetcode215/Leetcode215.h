//
// Created by cestl on 2018/5/3 0003.
//

#ifndef LEETCODE_LEETCODE215_H
#define LEETCODE_LEETCODE215_H

#include "config.h"

class Leetcode215 {
public:
    int findKthLargest2(vector<int> &nums, int k);

    int findKthLargest(vector<int> &nums, int k);

    void test215();

private:
    int partion(vector<int> &nums, int low, int high);
};


#endif //LEETCODE_LEETCODE215_H
