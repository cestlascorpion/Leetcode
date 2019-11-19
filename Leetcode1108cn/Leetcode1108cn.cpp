//
// Created by Wang on 2019/11/19.
//

#include "Leetcode1108cn.h"

string Leetcode1108cn::defangIPaddr(string address) {
    string res;
    for (const auto &ch : address) {
        if (ch != '.') {
            res.push_back(ch);
        } else {
            res += "[.]";
        }
    }
    return res;
}
