//
// Created by Wang on 2019/10/20.
//

#include "Leetcode925cn.h"

bool Leetcode925cn::isLongPressedName(string name, string typed) {
    int p = 0;
    int q = 0;
    while (p != name.size() && q != typed.size()) {
        if (name[p] != typed[q]) {
            return false;
        }

        int tmp;
        tmp = p;
        while (tmp != name.size() && name[tmp] == name[p]) {
            ++tmp;
        }
        int lp = tmp - p + 1;
        p = tmp;

        tmp = q;
        while (tmp != typed.size() && typed[tmp] == typed[q]) {
            ++tmp;
        }
        int lq = tmp - q + 1;
        q = tmp;
        if (lp > lq) {
            return false;
        }
    }
    return p == name.size();
}
