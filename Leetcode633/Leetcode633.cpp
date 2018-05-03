//
// Created by cestl on 2018/5/3 0003.
//

#include "Leetcode633.h"

bool Leetcode633::judgeSquareSum(int c) {
    int low = 0;
    int high = floor(sqrt(c));
    while (low <= high) {
        int sum = low * low + high * high;
        if (sum == c)
            return true;
        else if (sum > c)
            --high;
        else
            ++low;
    }
    return false;
}
