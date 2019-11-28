//
// Created by cestl on 2018/4/29 0029.
//

#ifndef LEETCODE_LEETCODE475_H
#define LEETCODE_LEETCODE475_H

#include "config.h"

class Leetcode475 {
public:
    int findRadius(vector<int> &houses, vector<int> &heaters);

    int findRadius2(vector<int> &houses, vector<int> &heaters);

    void test475();

private:
    int binarySearch(vector<int> &heaters, int target);

};


#endif //LEETCODE_LEETCODE475_H
