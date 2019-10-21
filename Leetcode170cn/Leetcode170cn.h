//
// Created by Wang on 2019/10/21.
//

#ifndef LEETCODE_LEETCODE170CN_H
#define LEETCODE_LEETCODE170CN_H

#include <config.h>

class Leetcode170cn {
public:
    /** Initialize your data structure here. */
    Leetcode170cn() {}

    /** Add the number to an internal data structure.. */
    void add(int number) { set.insert(number); }

    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        if (set.size() < 2) {
            return false;
        }
        auto iter = set.begin();
        auto jter = --set.end();
        while (iter != jter) {
            auto sum = *iter + *jter;
            if (sum == value) {
                return true;
            }
            if (sum > value) {
                --jter;
            } else {
                ++iter;
            }
        }
        return false;
    }

private:
    multiset<int> set;
};

#endif // LEETCODE_LEETCODE170CN_H
