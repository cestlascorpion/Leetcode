//
// Created by Wang on 2019/10/19.
//

#ifndef LEETCODE_LEETCODE146CN_H
#define LEETCODE_LEETCODE146CN_H

#include <list>
#include <unordered_map>

using std::list;
using std::pair;
using std::unordered_map;

class Leetcode146cn {
public:
    explicit Leetcode146cn(int capacity);

    int get(int key);

    void put(int key, int value);

private:
    int m_cap;
    list<pair<int, int>> m_busy;
    unordered_map<int, list<pair<int, int>>::iterator> m_map;
};

#endif // LEETCODE_LEETCODE146CN_H
