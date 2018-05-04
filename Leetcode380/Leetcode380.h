//
// Created by cestl on 2018/5/4 0004.
//

#ifndef LEETCODE_LEETCODE380_H
#define LEETCODE_LEETCODE380_H

#include "../config.h"

class Leetcode380 {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {

    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (hash.find(val) != hash.end())
            return false;
        vec.push_back(val);
        hash[val] = vec.size() - 1;
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (hash.find(val) == hash.end())
            return false;
        //交换vec末尾元素和待删除元素，然后删除末尾元素
        //vec.back()->val原来的索引位置（hash[val])，删除val->hash[val]
        vec[hash[val]] = vec.back();
        hash[vec.back()] = hash[val];
        vec.pop_back();
        hash.erase(val);
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        return vec[rand() % vec.size()];
    }

private:
    vector<int> vec;//val
    unordered_map<int, int> hash;//val->index in vec
};


#endif //LEETCODE_LEETCODE380_H
