//
// Created by Wang on 2019/10/13.
//

#include "Leetcode231cn.h"

bool Leetcode231cn::isPowerOfTwo(int n) {
    if (n <= 0)
        return false;

    int count = 0;
    while (n != 0) {
        if ((n & 0x1u) != 0) {
            ++count;
        }
        if (count > 1) {
            return false;
        }
        n = n >> 1u;
    }
    return count != 0;
}

bool Leetcode231cn::isPowerOfTwo2(int n) {
    if (n <= 0)
        return false;

    return (n & (n - 1)) == 0;
}
