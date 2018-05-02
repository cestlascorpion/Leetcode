//
// Created by cestl on 2018/5/2 0002.
//

#include "Leetcode492.h"

vector<int> Leetcode492::constructRectangle(int area) {
    vector<int> ans;
    if (area <= 0)
        return ans;
    int L = ceil(sqrt(area));
    int W = 1;
    while (L <= area) {
        if (area % L == 0) {
            W = area / L;
            ans.push_back(L);
            ans.push_back(W);
            break;
        }
        ++L;
    }
    return ans;
}
