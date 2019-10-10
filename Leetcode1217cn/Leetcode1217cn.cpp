//
// Created by hans-01829 on 10/11/19.
//

#include "Leetcode1217cn.h"

int Leetcode1217cn::minCostToMoveChips(vector<int> &chips) {
    if (chips.size() <= 1) {
        return 0;
    }

    int odd = 0;
    int even = 0;

    for (const auto &pos : chips) {
        if (pos & 0x1) {
            ++odd;
        } else {
            ++even;
        }
    }

    return std::min(odd, even);
}
