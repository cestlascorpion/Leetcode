//
// Created by Wang on 2019/10/13.
//

#include "Leetcode70cn.h"

int Leetcode70cn::climbStairs(int n) {
    if (n <= 2) {
        return n;
    }
    int step1 = 1;
    int step2 = 2;
    int res = 0;
    for (int i = 3; i <= n; ++i) {
        res = step1 + step2; // to step3 = to step1 + to step2
        step1 = step2; // for next step4 = to step2 + to step3
        step2 = res;
    }
    return res;
}
