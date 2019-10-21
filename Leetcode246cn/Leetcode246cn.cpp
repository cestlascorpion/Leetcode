//
// Created by Wang on 2019/10/21.
//

#include "Leetcode246cn.h"

bool Leetcode246cn::isStrobogrammatic(string num) {
    set<char> self{'0', '1', '8'};
    int p = 0;
    int q = num.size() - 1;
    while (p < q) {
        if ((num[p] == num[q] && self.find(num[p]) != self.end()) || (num[p] == '6' && num[q] == '9') ||
            (num[p] == '9' && num[q] == '6')) {
            ++p;
            --q;
        } else {
            return false;
        }
    }
    if (p == q) {
        return self.find(num[p]) != self.end();
    }
    return true;
}
