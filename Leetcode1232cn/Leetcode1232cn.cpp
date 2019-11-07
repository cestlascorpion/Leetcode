//
// Created by Wang on 2019/11/7.
//

#include "Leetcode1232cn.h"

bool Leetcode1232cn::checkStraightLine(vector<vector<int>> &coordinates) {
    if (coordinates.size() == 2) {
        return true;
    }
    // x-x0/y-y0 = x1-x0/y1-y0
    for (int i = 2; i < coordinates.size(); ++i) {
        if ((coordinates[i][0] - coordinates[0][0]) * (coordinates[1][1] - coordinates[0][1]) !=
            (coordinates[i][1] - coordinates[0][1]) * (coordinates[1][0] - coordinates[0][0])){
            return false;
        }
    }
    return true;
}
