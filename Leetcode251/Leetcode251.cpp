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

Leetcode251x::Leetcode251x(vector<vector<int>> &vec2d) {
    v = vec2d;
    x = y = 0;
}

int Leetcode251x::next() {
    return v[x][y++];
}

bool Leetcode251x::hasNext() {
    while (x < v.size() && y == v[x].size()) {
        ++x;
        y = 0;
    }
    return x < v.size();
}
