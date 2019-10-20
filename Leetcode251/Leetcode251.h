//
// Created by cestl on 2018/5/4 0004.
//

#ifndef LEETCODE_LEETCODE251_H
#define LEETCODE_LEETCODE251_H

#include <config.h>

class Leetcode251 {
public:
    Leetcode251(vector<vector<int>> &vec2d);

    int next();

    bool hasNext();

private:
    vector<int> v;
    int i = 0;
};

class Leetcode251x {
public:
    Leetcode251x(vector<vector<int>> &vec2d);

    int next();

    bool hasNext();

private:
    vector<vector<int>> v;
    int x, y;
};

#endif //LEETCODE_LEETCODE251_H
