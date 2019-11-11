//
// Created by Wang on 2019/11/8.
//

#include "Leetcode392cn.h"

bool Leetcode392cn::isSubsequence(string s, string t) {
    if (s.empty())
        return true;
    int a = 0;
    int len = s.size();
    for (char i : t) {
        if (s[a] == i)
            a++;
        if (a == len)
            return true;
    }
    return false;
}
