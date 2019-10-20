//
// Created by Wang on 2019/10/20.
//

#include "Leetcode415cn.h"

string Leetcode415cn::addStrings(string num1, string num2) {
    int len = max(num1.size(), num2.size());
    string res(len, '0');
    int flow = 0;
    for (int i = 0; i < res.size(); ++i) {
        int a = i < num1.size() ? (num1[num1.size() - 1 - i] - '0') : 0;
        int b = i < num2.size() ? (num2[num2.size() - 1 - i] - '0') : 0;
        flow += a + b;
        res[res.size() - 1 - i] = char((flow % 10) + '0');
        flow /= 10;
    }
    if (flow != 0) {
        res = char(flow + '0') + res;
    }
    return res;
}
