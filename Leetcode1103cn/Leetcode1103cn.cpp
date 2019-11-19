//
// Created by Wang on 2019/11/19.
//

#include "Leetcode1103cn.h"

vector<int> Leetcode1103cn::distributeCandies(int candies, int num_people) {
    vector<int> res(num_people, 0);
    int num = 1;
    int idx = 0;
    while (candies > num) {
        res[idx] += num;
        candies -= num;
        ++num;
        idx = (idx + 1) % num_people;
    }
    res[idx] += candies;
    return res;
}
