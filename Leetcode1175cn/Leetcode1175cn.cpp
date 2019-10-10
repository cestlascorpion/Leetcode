//
// Created by Wang on 2019/10/10.
//
#include "Leetcode1175cn.h"

int Leetcode1175cn::numPrimeArrangements(int n) {
    vector<int> prime{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    int m = 0; // prime count
    for (const int num : prime) {
        if (n >= num) {
            ++m;
        } else {
            break;
        }
    }
    uint64_t res = 1;
    for (uint64_t i = m; i > 1; --i) {
        res *= i;
        res %= 1000000007;
    }
    for (uint64_t i = n - m; i > 1; --i) {
        res *= i;
        res %= 1000000007;
    }
    cout << m << " " << n - m << endl;
    return (int) res;
}
