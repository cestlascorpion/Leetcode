//
// Created by Wang on 2019/10/20.
//

#include "Leetcode492cn.h"

vector<int> Leetcode492cn::constructRectangle(int area) {
    int H = sqrt(area);
    while (area % H != 0) {
        --H;
    }
    return {H, area / H};
}
