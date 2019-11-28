//
// Created by cestl on 2018/5/3 0003.
//

#ifndef LEETCODE_LEETCODE598_H
#define LEETCODE_LEETCODE598_H

#include "config.h"

class Leetcode598 {
public:
    int maxCount(int m, int n, vector<vector<int>> &ops) {
        if (ops.empty())
            return m * n;

        int a = INT32_MAX, b = INT32_MAX;
        for (int i = 0; i < ops.size(); ++i) {
            if (a > ops[i][0])
                a = ops[i][0];
            if (b > ops[i][1])
                b = ops[i][1];
        }
        return a * b;
    }
};

#endif //LEETCODE_LEETCODE598_H
