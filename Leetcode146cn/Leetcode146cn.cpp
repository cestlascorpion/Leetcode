//
// Created by Wang on 2019/10/19.
//

#include "Leetcode146cn.h"

Leetcode146cn::Leetcode146cn(int capacity) { m_cap = capacity; }

int Leetcode146cn::get(int key) {
    int value = -1;
    auto iter = m_map.find(key);
    if (iter != m_map.end()) {
        value = iter->second->second;
        m_busy.splice(m_busy.begin(), m_busy, iter->second);
        m_map[key] = m_busy.begin();
    }
    return value;
}

void Leetcode146cn::put(int key, int value) {
    auto iter = m_map.find(key);
    if (iter != m_map.end()) {
        m_busy.erase(iter->second);
        m_map.erase(key);
    }
    while (m_busy.size() >= m_cap) {
        m_map.erase(m_busy.back().first);
        m_busy.pop_back();
    }
    m_busy.emplace_front(key, value);
    m_map.emplace(key, m_busy.begin());
}
