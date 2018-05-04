//
// Created by cestl on 2018/5/4 0004.
//

#include "Leetcode69.h"

int Leetcode69::mySqrt(int x) {
    if (x <= 1)
        return x;
    int left = 0, right = x;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (x / mid >= mid) left = mid + 1;
        else right = mid;
    }
    return right - 1;
}
