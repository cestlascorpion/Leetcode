//
// Created by cestl on 2018/5/15 0015.
//

#include "Leetcode146.h"

int Leetcode146::get(int key) {
    if (m_cache.find(key) == m_cache.end())
        return -1;
    auto pos = m_cache[key];
    auto ans = *pos;
    m_LRU_queue.erase(pos);
    m_LRU_queue.push_front(ans);
    m_cache[key] = m_LRU_queue.begin();
    return ans.value;
}

void Leetcode146::put(int key, int value) {
    if (get(key) != -1) {
        m_cache[key]->value = value;
        return;
    }
    m_LRU_queue.emplace_front(key, value);
    m_cache[key] = m_LRU_queue.begin();

    while (m_LRU_queue.size() > m_capacity) {
        m_cache.erase(m_LRU_queue.back().key);
        m_LRU_queue.pop_back();
    }
}
