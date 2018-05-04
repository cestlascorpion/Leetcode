//
// Created by cestl on 2018/5/4 0004.
//

#include "Leetcode251.h"

Leetcode251::Leetcode251(vector<vector<int>> &vec2d) {
    for (auto a : vec2d)
        v.insert(v.end(), a.begin(), a.end());
}

int Leetcode251::next() {
    return v[i++];
}

bool Leetcode251::hasNext() {
    return i < v.size();
}
