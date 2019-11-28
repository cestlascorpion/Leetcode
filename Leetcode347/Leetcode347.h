//
// Created by cestl on 2018/4/29 0029.
//

#ifndef LEETCODE_LEETCODE347_H
#define LEETCODE_LEETCODE347_H

#include "config.h"

class Leetcode347 {
public:
    vector<int> topKFrequent(vector<int> &nums, int k);

    void test347();

private:
    struct Node {
        int _x, _y;

        Node(int x, int y) : _x(x), _y(y) {};
    };

    friend bool operator<(const Node &a, const Node &b);
};


#endif //LEETCODE_LEETCODE347_H
