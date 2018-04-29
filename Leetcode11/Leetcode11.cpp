//
// Created by cestl on 2018/4/29 0029.
//

#include "Leetcode11.h"

int Leetcode11::maxArea(vector<int> &height) {
    int left = 0;
    int right = height.size() - 1;
    int area = 0;
    while (left < right) {
        area = max(area, (right - left) * min(height.at(left), height.at(right)));
        if (height.at(left) < height.at(right))
            ++left;
        else
            --right;
    }
    return area;
}
