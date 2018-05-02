//
// Created by cestl on 2018/5/2 0002.
//

#include "Leetcode521.h"

int Leetcode521::findLUSlength(string a, string b) {
    return a == b ? -1 : max(a.size(), b.size());
}
