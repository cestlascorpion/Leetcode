//
// Created by Wang on 2019/12/4.
//

#include "Leetcode961cn.h"

int Leetcode961cn::repeatedNTimes(vector<int> &A) {
    set<int> set;
    for (const auto &num : A) {
        if (set.count(num) != 0)
            return num;
        set.insert(num);
    }
    return -1;
}
