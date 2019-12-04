//
// Created by Wang on 2019/12/4.
//

#include "Leetcode806cn.h"

vector<int> Leetcode806cn::numberOfLines(vector<int> &widths, string S) {
    vector<int> res(2, 0);
    int used = 0;
    int line = 0;
    for (const auto &ch : S) {
        if (used + widths[ch - 'a'] > 100) {
            used = 0;
            ++line;
            used += widths[ch - 'a'];
        } else if (used + widths[ch - 'a'] == 100) {
            used = 0;
            ++line;
        } else {
            used += widths[ch - 'a'];
        }
    }
    res[0] = line + used > 0 ? 1 : 0;
    res[1] = used;
    return res;
}
