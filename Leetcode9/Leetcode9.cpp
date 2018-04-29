//
// Created by cestl on 2018/4/29 0029.
//

#include "Leetcode9.h"

bool Leetcode9::isPalindrome(int x) {
    if (x < 0 || (x != 0 && x % 10 == 0))
        return false;
    int sum = 0;
    while (x > sum) {
        sum = sum * 10 + x % 10;
        x = x / 10;
    }
    return (x == sum) || (x == sum / 10);
}
