//
// Created by Wang on 2019/12/2.
//

#ifndef LEETCODE_LEETCODE705CN_H
#define LEETCODE_LEETCODE705CN_H

#include "config.h"

class MyHashSet {
public:
    enum { LENGTH = 999983 };

public:
    /** Initialize your data structure here. */
    MyHashSet() { m_buckets.resize(LENGTH); }

    void add(int key) {
        auto &list = m_buckets[key % LENGTH];
        auto iter = find(list.begin(), list.end(), key);
        if (iter == list.end()) {
            list.push_back(key);
        }
    }

    void remove(int key) {
        auto &list = m_buckets[key % LENGTH];
        auto iter = find(list.begin(), list.end(), key);
        if (iter != list.end()) {
            list.erase(iter);
        }
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        auto &list = m_buckets[key % LENGTH];
        auto iter = find(list.begin(), list.end(), key);
        return iter != list.end();
    }

private:
    vector<list<int>> m_buckets;
};

#endif // LEETCODE_LEETCODE705CN_H
