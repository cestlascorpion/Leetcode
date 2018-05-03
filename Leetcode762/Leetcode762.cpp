//
// Created by cestl on 2018/5/3 0003.
//

#include "Leetcode762.h"

int Leetcode762::countPrimeSetBits(int L, int R) {
    int ans = 0;
    if (L > R)
        return ans;
    primes.insert(2);
    primes.insert(3);
    primes.insert(5);
    primes.insert(7);
    primes.insert(11);
    primes.insert(13);
    primes.insert(17);
    primes.insert(19);
    for (int i = L; i <= R; ++i) {
        int bits = getBits(i);
        if (isPrime(bits))
            ++ans;
    }
    return ans;
}

int Leetcode762::getBits(int num) {
    int res = 0;
    while (num) {
        if ((num & 1) == 1)
            ++res;
        num = num >> 1;
    }
    return res;
}

bool Leetcode762::isPrime(int num) {
    if (primes.count(num) == 0)
        return false;
    else
        return true;
}
