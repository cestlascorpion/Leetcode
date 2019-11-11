//
// Created by Wang on 2019/11/10.
//

#include "Leetcode89cn.h"

vector<int> Leetcode89cn::grayCode(int n) {
    vector<int> v((1 << n), 0);
    for (int i = 1 << n; i--; v[i] = i ^ (i >> 1)) {
    }
    return v;
}
