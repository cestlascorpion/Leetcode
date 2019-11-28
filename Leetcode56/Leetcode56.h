//
// Created by cestl on 2018/5/3 0003.
//

#ifndef LEETCODE_LEETCODE56_H
#define LEETCODE_LEETCODE56_H

#include "config.h"

struct Interval {
    int start;
    int end;

    Interval() : start(0), end(0) {}

    Interval(int s, int e) : start(s), end(e) {}
};

class Leetcode56 {
public:
    vector<Interval> merge(vector<Interval> &intervals);

    void test56();
};


#endif //LEETCODE_LEETCODE56_H
