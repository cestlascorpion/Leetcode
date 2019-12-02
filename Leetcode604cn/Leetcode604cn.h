//
// Created by Wang on 2019/12/2.
//

#ifndef LEETCODE_LEETCODE604CN_H
#define LEETCODE_LEETCODE604CN_H

#include "config.h"

class Leetcode604cn {
public:
    Leetcode604cn(string str) {
        for (int i = 0; i < str.size();) {
            int j = i + 1;
            while (j < str.size() && (str[j] >= '0' && str[j] <= '9')) {
                ++j;
            }
            m_queue.push({str[i], stoi(str.substr(i + 1, j - i).c_str(), nullptr, 10)});
            i = j;
        }
    }

    char next() {
        auto res = m_queue.front().first;
        if (--m_queue.front().second == 0) {
            m_queue.pop();
        }
        return res;
    }

    bool hasNext() { return !m_queue.empty(); }

private:
    queue<pair<char, int>> m_queue;
};

#endif // LEETCODE_LEETCODE604CN_H
