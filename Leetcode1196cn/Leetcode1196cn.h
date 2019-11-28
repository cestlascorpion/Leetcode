//
// Created by Wang on 2019/11/7.
//

#ifndef LEETCODE_LEETCODE1196CN_H
#define LEETCODE_LEETCODE1196CN_H

#include "config.h"

class Leetcode1196cn {
public:
    int maxNumberOfApples(vector<int> &arr) {
        int ans = 0;
        int curr = 5000;

        sort(arr.begin(), arr.end());
        for (int i : arr) {
            curr -= i;
            if (curr >= 0) {
                ++ans;
            } else {
                break;
            }
        }
        return ans;
    }
};

#endif // LEETCODE_LEETCODE1196CN_H
