//
// Created by Wang on 2019/11/29.
//

#include "Leetcode504cn.h"

string Leetcode504cn::convertToBase7(int num) {
    if(num == 0) return "0";
    bool negative = num < 0;
    num = abs(num);
    string res;
    while (num != 0) {
        res.push_back(num % 7 + '0');
        num = num / 7;
    }
    if (negative)
        res += '-';
    reverse(res.begin(), res.end());
    return res;
}
