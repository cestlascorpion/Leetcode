//
// Created by cestl on 2018/5/4 0004.
//

#ifndef LEETCODE_LEETCODE172_H
#define LEETCODE_LEETCODE172_H

#include "../config.h"

class Leetcode172 {
public:
    int trailingZeroes(int n) {
        return n == 0 ? 0 : n / 5 + trailingZeroes(n / 5);
    }
};


#endif //LEETCODE_LEETCODE172_H
