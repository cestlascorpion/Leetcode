//
// Created by hans on 4/27/18.
//

#ifndef LEETCODE_LEETCODE155_H
#define LEETCODE_LEETCODE155_H

#include "../config.h"

class Leetcode155 {
public:
    Leetcode155();

    void push(int x);

    void pop();

    int top();

    int getMin();

private:
    stack<int> s1;
    stack<int> s2;
};


#endif //LEETCODE_LEETCODE155_H
