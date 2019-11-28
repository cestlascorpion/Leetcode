//
// Created by cestl on 2018/5/2 0002.
//

#ifndef LEETCODE_LEETCODE485_H
#define LEETCODE_LEETCODE485_H

#include "config.h"

class Leetcode485 {
public:
    int findMaxConsecutiveOnes(vector<int> &nums) {
        if (nums.empty())
            return 0;

        int ans = 0;
        int cnt = 0;
        int i = 0;
        while (i < nums.size()) {
            while (nums[i] != 1 && i < nums.size())
                ++i;
            while (nums[i] == 1 && i < nums.size()) {
                ++cnt;
                ++i;
            }
            ans = cnt > ans ? cnt : ans;
            cnt = 0;
        }
        return ans;
    }
};


#endif //LEETCODE_LEETCODE485_H
