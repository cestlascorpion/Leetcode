//
// Created by cestl on 2018/5/3 0003.
//

#ifndef LEETCODE_LEETCODE322_H
#define LEETCODE_LEETCODE322_H

#include "../config.h"

class Leetcode322 {
public:
    //找零钱的方法数量
    int coinChange(vector<int> &coins, int amount);
    //最少需要的硬币的个数
    int coinChangeMethods(vector<int> &coins, int amount);

    void test322();
};


#endif //LEETCODE_LEETCODE322_H
