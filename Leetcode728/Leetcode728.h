//
// Created by cestl on 2018/5/3 0003.
//

#ifndef LEETCODE_LEETCODE728_H
#define LEETCODE_LEETCODE728_H

#include "../config.h"

class Leetcode728 {
public:
    vector<int> selfDividingNumbers(int left, int right);

private:
    bool isValid(int i);
};

class Solution2 {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> rslt;
        for (int n = left; n <= right; n++) {
            if (isSelfDividing(n))
                rslt.push_back(n);
        }
        return rslt;
    }

    bool isSelfDividing(int n) {
        int x = n;
        while (x) {
            int d = x % 10;
            if (d == 0)
                return false;
            if (n % d != 0)
                return false;
            x = x / 10;
        }
        return true;
    }
};


#endif //LEETCODE_LEETCODE728_H
