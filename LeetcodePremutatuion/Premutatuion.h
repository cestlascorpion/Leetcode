//
// Created by cestl on 2018/4/27 0027.
//

#ifndef LEETCODE_PREMUTATUION_H
#define LEETCODE_PREMUTATUION_H

#include "../config.h"

class Premutatuion {
public:
    vector<vector<int>> premutatuion(vector<int> &nums);

    void testPremutatuion();

private:
    void premutatuionhelper(vector<int> nums, int begin, int end,
                            vector<vector<int>> &ans);
};


#endif //LEETCODE_PREMUTATUION_H
