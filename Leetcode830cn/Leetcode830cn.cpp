//
// Created by Wang on 2019/12/4.
//

#include "Leetcode830cn.h"

vector<vector<int>> Leetcode830cn::largeGroupPositions(string S) {
    vector<vector<int>> res;
    int i = 0;
    while (i < S.size()) {
        int j = i + 1;
        while (j < S.size() && S[j] == S[i]) {
            ++j;
        }
        if (j - i >= 3) {
            vector<int> tmp = {i, j - 1};
            res.push_back(move(tmp));
        }
        i = j;
    }
    return res;
}
