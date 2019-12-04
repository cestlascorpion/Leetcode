//
// Created by Wang on 2019/12/3.
//

#include "Leetcode754cn.h"

int Leetcode754cn::reachNumber(int target) {
    target = abs(target);
    int k = 0;
    int sum = 0;
    while (sum < target) {
        ++k;
        sum += k;
    }
    if (sum == target)
        return k;
    int delta = sum - delta;
    if (delta % 2 == 0)
        return k;
    if ((delta + k + 1) % 2 == 0)
        return k + 1;
    return k + 2;
}
