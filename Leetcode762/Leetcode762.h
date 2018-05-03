//
// Created by cestl on 2018/5/3 0003.
//

#ifndef LEETCODE_LEETCODE762_H
#define LEETCODE_LEETCODE762_H

#include "../config.h"

class Leetcode762 {
public:
    int countPrimeSetBits(int L, int R);

private:
    int getBits(int num);

    bool isPrime(int num);

    set<int> primes;
};


#endif //LEETCODE_LEETCODE762_H
