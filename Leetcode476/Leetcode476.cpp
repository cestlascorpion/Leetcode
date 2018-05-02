//
// Created by cestl on 2018/5/2 0002.
//

#include "Leetcode476.h"

int Leetcode476::findComplement(int num) {
    int mask = 1, temp = num;
    while (temp > 0) {
        mask = mask << 1;
        temp = temp >> 1;
    }
    return num ^ (mask - 1);
}
