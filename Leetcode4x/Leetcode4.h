//
// Created by cestl on 2018/4/29 0029.
//

#ifndef LEETCODE_LEETCODE4_H
#define LEETCODE_LEETCODE4_H

#include "config.h"

class Leetcode4 {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2);

private:
    double findKth(vector<int> &nums1, int i1, vector<int> &nums2, int i2, int k);
};

#endif //LEETCODE_LEETCODE4_H
