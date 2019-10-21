//
// Created by Wang on 2019/10/21.
//

#include "Leetcode243cn.h"

int Leetcode243cn::shortestDistance(vector<string> &words, string word1, string word2) {
    int res = words.size();
    int p = -1;
    int q = -1;
    for (int i = 0; i < words.size(); ++i) {
        if (word1 == words[i]) {
            p = i;
            if (q != -1)
                res = min(res, abs(p - q));
        } else if (word2 == words[i]) {
            q = i;
            if (p != -1)
                res = min(res, abs(p - q));
        } else {
            continue;
        }
    }
    return res;
}
