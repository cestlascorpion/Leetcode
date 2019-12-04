//
// Created by Wang on 2019/12/4.
//

#include "Leetcode836cn.h"

bool Leetcode836cn::isRectangleOverlap(vector<int> &rec1, vector<int> &rec2) {
    return !(rec1[2] <= rec2[0] || rec1[0] >= rec2[2] || rec1[1] >= rec2[3] || rec1[3] <= rec2[1]);
}
