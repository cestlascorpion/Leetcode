//
// Created by Wang on 2019/11/27.
//

#include "Leetcode405cn.h"

string Leetcode405cn::toHex(int num) {
    if (num == 0)
        return "0";
    string res;
    string hex[16] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "a", "b", "c", "d", "e", "f"};
    unsigned int n = num;
    while (n != 0) {
        res = hex[n % 16] + res;
        n /= 16;
    }
    return res;
}
