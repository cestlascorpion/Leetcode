//
// Created by Wang on 2019/11/27.
//

#include "Leetcode422cn.h"

bool Leetcode422cn::validWordSquare(vector<string> &words) {
    if (words.empty())
        return true;
    int vlen = words.size();
    for (int i = 0; i < vlen; ++i) {
        int slen = words[i].size();
        for (int j = 0; j < slen; ++j) {
            if (vlen <= j) return false;
            if (words[j].size() <= i) return false;
            if (words[j][i] != words[i][j]) return false;
        }
    }
    return true;
}
