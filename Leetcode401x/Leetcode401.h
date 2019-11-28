//
// Created by cestl on 2018/4/29 0029.
//

#ifndef LEETCODE_LEETCODE401_H
#define LEETCODE_LEETCODE401_H

#include "config.h"

class Leetcode401 {
public:
    vector<string> readBinaryWatch(int num);

private:
    void helper(vector<string> &ans, vector<int> &chart,
                int &num, int cur, int idx, int hour, int min);
};


#endif //LEETCODE_LEETCODE401_H
