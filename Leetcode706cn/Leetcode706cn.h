//
// Created by Wang on 2019/12/2.
//

#ifndef LEETCODE_LEETCODE706CN_H
#define LEETCODE_LEETCODE706CN_H

#include "config.h"

class MyHashMap {
public:
    enum { LENGTH = 997 };

public:
    /** Initialize your data structure here. */
    MyHashMap() { m_buckets.resize(LENGTH); }

    /** value will always be non-negative. */
    void put(int key, int value) {
        auto &list = m_buckets[key % LENGTH];
        for (auto &iter : list) {
            if (iter.first == key) {
                iter.second = value;
                return;
            }
        }
        list.emplace_back(key, value);
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        auto &list = m_buckets[key % LENGTH];
        for (auto &iter : list) {
            if (iter.first == key) {
                return iter.second;
            }
        }
        return -1;
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        auto &list = m_buckets[key % LENGTH];
        for (auto iter = list.begin(); iter != list.end(); ++iter) {
            if (iter->first == key) {
                list.erase(iter);
                return;
            }
        }
    }

private:
    vector<list<pair<const int, int>>> m_buckets;
};

#endif // LEETCODE_LEETCODE706CN_H
