//
// Created by Wang on 2019/11/12.
//

#include "Leetcode342cn.h"

bool Leetcode342cn::isPowerOfFour(int num) {
    if (num < 0) {
        return false;
    }
    bool even = true;
    int found = 0;
    for (int i = 0; i < 32; ++i) {
        if ((0x1 & num) == 1) {
            if (!even) {
                return false;
            }
            ++found;
        }
        num = num >> 1;
        even = !even;
    }
    return found == 1;
}
