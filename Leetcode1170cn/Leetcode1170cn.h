//
// Created by hans-01829 on 10/11/19.
//

#ifndef LEETCODE_LEETCODE1170CN_H
#define LEETCODE_LEETCODE1170CN_H

#include "../config.h"

class Leetcode1170cn {
public:
    vector<int> numSmallerByFrequency(vector<string> &queries, vector<string> &words) ;

    int f(const string &word) {
        char dict[26] = {0};
        for (const auto &ch : word) {
            int pos = ch - 'a';
            if (pos < 0 || pos > 25) {
                continue;
            }
            ++dict[pos];
        }
        for (const auto &ch : dict) {
            if (ch > 0) {
                return ch;
            }
        }
        return 0;
    }
};

#endif // LEETCODE_LEETCODE1170CN_H
