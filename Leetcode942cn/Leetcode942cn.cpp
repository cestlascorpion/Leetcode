//
// Created by Wang on 2019/12/19.
//

#include "Leetcode942cn.h"

vector<int> Leetcode942cn::diStringMatch(string S) {
    vector<int> res(S.size() + 1);
    int min = 0;
    int max = S.size();
    for (int i = 0; i < S.size(); ++i) {
        if (S[i] == 'I') {
            res[i] = min++;
        } else {
            res[i] = max--;
        }
    }
    res[S.size()] = min++;
    return res;
}
