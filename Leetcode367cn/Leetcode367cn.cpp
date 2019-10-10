//
// Created by Wang on 2019/10/13.
//

#include "Leetcode367cn.h"

bool Leetcode367cn::isPerfectSquare(int num) {
    if (num <= 1) return true;

    int lo = 1, hi = num / 2;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (mid >= num / mid) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    return (long) lo * lo == num;
}
