//
// Created by cestl on 2018/5/15 0015.
//

#ifndef LEETCODE_LEETCODE146_H
#define LEETCODE_LEETCODE146_H

#include "config.h"

class Leetcode146 {
public:
    Leetcode146(int capacity) : m_capacity(capacity) {}

    int get(int key);

    void put(int key, int value);

private:
    struct kvPair {
        int key, value;

        kvPair(int k, int v) : key(k), value(v) {}
    };

    list<kvPair> m_LRU_queue;
    unordered_map<int, list<kvPair>::iterator> m_cache;
    int m_capacity;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

#endif //LEETCODE_LEETCODE146_H
