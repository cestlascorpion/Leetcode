//
// Created by Wang on 2019/11/20.
//

#include "Leetcode1046cn.h"

int Leetcode1046cn::lastStoneWeight(vector<int> &stones) {
    if (stones.empty()) {
        return 0;
    }
    priority_queue<int, vector<int>, less<int>> pq(stones.begin(), stones.end());
    while (!pq.empty() && pq.size() != 1) {
        int s1 = pq.top();
        pq.pop();
        int s2 = pq.top();
        pq.pop();
        if (s1 == s2) {
            continue;
        }
        pq.push(s1 - s2);
    }
    if (pq.empty()) {
        return 0;
    }
    return pq.top();
}
