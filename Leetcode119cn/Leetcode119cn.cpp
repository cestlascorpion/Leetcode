//
// Created by Wang on 2019/10/13.
//

#include "Leetcode119cn.h"

//   1
//  1 1
// 1 x 1
vector<int> Leetcode119cn::getRow(int rowIndex) {
    int x = 0;
    vector<int> rowx = {1};
    while (x != rowIndex) {
        ++x;
        rowx.insert(rowx.begin(), 0);
        for (int i = 0; i < rowx.size() - 1; ++i) {
            rowx[i] = rowx[i] + rowx[i + 1];
        }
    }
    return rowx;
}
