//
// Created by cestl on 2018/5/4 0004.
//

#ifndef LEETCODE_LEETCODE202_H
#define LEETCODE_LEETCODE202_H

#include "config.h"

class Leetcode202 {
public:
    bool isHappy(int n);

    void test202();

private:
    unordered_set<int> s{4, 16, 37, 58, 89, 145, 42, 20};
};


#endif //LEETCODE_LEETCODE202_H
