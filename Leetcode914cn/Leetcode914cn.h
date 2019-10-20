//
// Created by Wang on 2019/10/13.
//

#ifndef LEETCODE_LEETCODE914CN_H
#define LEETCODE_LEETCODE914CN_H

#include <config.h>

class Leetcode914cn {
public:
    bool hasGroupsSizeX(vector<int> &deck);
    bool hasGroupsSizeX2(vector<int> &deck);

private:
    int gcd(int a, int b);
};

#endif //LEETCODE_LEETCODE914CN_H
