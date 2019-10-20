//
// Created by cestl on 2018/5/3 0003.
//

#ifndef LEETCODE_LEETCODE605_H
#define LEETCODE_LEETCODE605_H

#include <config.h>

class Leetcode605 {
public:
    bool canPlaceFlowers(vector<int> &bed, int n);
    bool canPlaceFlowers2(vector<int> &flowerbed, int n);
    int maxFlowers(int n)
    {
        if ((n & 1) == 1)
            return n >> 1;
        else
            return (n >> 1) - 1;
    }
};


#endif //LEETCODE_LEETCODE605_H
