//
// Created by cestl on 2018/4/29 0029.
//

#include "Leetcode258.h"

int Leetcode258::addDigits(int num) {
    if (num / 10 == 0)
        return num;
    else {
        int s = 0;
        int n = num;
        while (n) {
            s += n % 10;
            n = n / 10;
        }
        return addDigits(s);
    }
}

int Leetcode258::addDigits2(int num) {
    if (num == 0)
        return 0;
    if (num % 9 == 0)
        return 9;
    return num % 9;
}
