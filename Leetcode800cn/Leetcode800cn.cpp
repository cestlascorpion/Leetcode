//
// Created by Wang on 2019/12/3.
//

#include "Leetcode800cn.h"

string Leetcode800cn::similarRGB(string color) {
    return "#" + get_min(color.substr(1, 2)) + get_min(color.substr(3, 2)) + get_min(color.substr(5, 2));
}

string Leetcode800cn::get_min(const string &AB) {
    int num1 = stoi(AB.substr(0, 1), nullptr, 16);
    int num2 = stoi(AB.substr(1, 1), nullptr, 16);
    int upper = num1 == 15 ? 15 : num1 + 1;
    int lower = num1 == 0 ? 0 : num1 - 1;

    int delta = INT32_MAX;
    int min_num = num1;
    for (int i = lower; i <= upper; ++i) {
        int tmp = abs(i * 16 + i - num1 * 16 - num2);
        if (tmp < delta) {
            delta = tmp;
            min_num = i;
        }
    }
    char s = min_num < 10 ? char(min_num + '0') : (char(min_num - 10 + 'a'));
    string res;
    res.push_back(s);
    res.push_back(s);
    return res;
}
