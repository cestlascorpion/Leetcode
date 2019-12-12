//
// Created by Wang on 2019/12/12.
//

#include "Leetcode849cn.h"

int Leetcode849cn::maxDistToClosest(vector<int> &seats) {
    int d = 0, d1 = 0, d2 = 0;
    int i = 0, j = seats.size() - 1;
    while (0 == seats[i++])
        d1++;
    while (0 == seats[j--])
        d2++;
    d = max(d1, d2);
    d1 = 0;
    while (i <= j) {
        while (0 == seats[i++])
            d1++;
        d = max(d, (d1 + 1) / 2);
        d1 = 0;
    }
    return d;
}
