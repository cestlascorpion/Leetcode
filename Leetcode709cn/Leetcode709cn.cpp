//
// Created by Wang on 2019/11/12.
//

#include "Leetcode709cn.h"

string Leetcode709cn::toLowerCase(string str) {
    for (auto &ch:str) {
        if (ch >= 'A' && ch <= 'Z') {
            ch = ch - 'A' + 'a';
        }
    }
    return str;
}
