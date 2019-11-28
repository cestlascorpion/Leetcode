//
// Created by cestl on 2018/5/4 0004.
//

#ifndef LEETCODE_LEETCODE380_H
#define LEETCODE_LEETCODE380_H

#include "config.h"

class Leetcode380 {
public:
    /** Initialize your data structure here. */
    Leetcode380(){}

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val);

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val);

    /** Get a random element from the set. */
    int getRandom();

private:
    vector<int> vec;//val
    unordered_map<int, int> hash;//val->index in vec
};


#endif //LEETCODE_LEETCODE380_H
