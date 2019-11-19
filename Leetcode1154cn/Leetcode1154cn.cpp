//
// Created by Wang on 2019/11/19.
//

#include "Leetcode1154cn.h"

int Leetcode1154cn::dayOfYear(string date) {
    // xxxx-xx-xx
    vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    auto year = strtoul(date.substr(0, 4).c_str(), nullptr, 10);
    auto month = strtoul(date.substr(5, 2).c_str(), nullptr, 10);
    auto day = strtoul(date.substr(8, 2).c_str(), nullptr, 10);
    bool flag = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    int res = day;
    for (int i = 0; i < month - 1; ++i) {
        res += days[i];
    }
    if (month > 2 && flag) {
        res += 1;
    }
    return res;
}
