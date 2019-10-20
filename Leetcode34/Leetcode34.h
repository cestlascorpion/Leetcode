//
// Created by cestl on 2018/5/3 0003.
//

#ifndef LEETCODE_LEETCODE34_H
#define LEETCODE_LEETCODE34_H

#include <config.h>

class Leetcode34 {
public:
    vector<int> searchRange(vector<int> &nums, int target);

    void test34();

private:
    int binarySearchLow(vector<int> &nums, int begin, int end, int target);

    int binarySearchHigh(vector<int> &nums, int begin, int end, int target);
};


#endif //LEETCODE_LEETCODE34_H
