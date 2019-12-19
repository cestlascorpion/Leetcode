//
// Created by Wang on 2019/12/19.
//

#ifndef LEETCODE_LEETCODE933CN_H
#define LEETCODE_LEETCODE933CN_H

#include "config.h"

class RecentCounter {
public:
    enum { INTERVAL = 3000 };

public:
    RecentCounter() {}

    int ping(int t) {
        m_require.push(t);
        while (!m_require.empty() && m_require.front() + INTERVAL < t) {
            m_require.pop();
        }
        return m_require.size();
    }

private:
    queue<int> m_require;
};

#endif // LEETCODE_LEETCODE933CN_H
