//
// Created by cestl on 2018/5/3 0003.
//

#include "Leetcode693.h"

bool Leetcode693::hasAlternatingBits(int n) {
    int flag = n & 1;
    do {
        n = n >> 1;
        if ((n & 1) == flag)
            return false;
        flag = n & 1;
    } while (n);
    return true;
}
