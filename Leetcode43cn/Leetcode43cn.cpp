//
// Created by Wang on 2019/10/15.
//

#include "Leetcode43cn.h"

string Leetcode43cn::multiply(string num1, string num2) {
    string res(max(num1.size(), num2.size()), '0');
    for (int i = 0; i != num2.size(); ++i) {
        auto tmp = multiply_base(num1, num2[num2.size() - 1 - i]);
        for (int j = 0; j < i; ++j) {
            tmp += "0";
        }
        res = add(res, tmp);
    }
    int pos = 0;
    while (pos != res.size() && res[pos] == '0') {
        ++pos;
    }
    if (pos == res.size()) {
        res = "0";
    } else {
        res = res.substr(pos);
    }

    return res;
}

string Leetcode43cn::multiply_base(string num, char ch) {
    if (ch == '0') {
        return "0";
    }

    string res(num.size(), '0');
    int base = to_num(ch);
    int flow = 0;
    for (int i = 0; i != num.size(); ++i) {
        int multi = to_num(num[num.size() - 1 - i]);
        int tmp = multi * base + flow;
        res[res.size() - 1 - i] = to_str(tmp % 10);
        flow = tmp / 10;
    }
    if (flow != 0) {
        res = to_str(flow) + res;
    }
    return res;
}

string Leetcode43cn::add(string num1, string num2) {
    string res(max(num1.size(), num2.size()), '0');
    int flow = 0;
    for (int i = 0; i < res.size(); ++i) {
        int a = i < num1.size() ? to_num(num1[num1.size() - 1 - i]) : 0;
        int b = i < num2.size() ? to_num(num2[num2.size() - 1 - i]) : 0;
        int c = a + b + flow;
        res[res.size() - 1 - i] = to_str(c % 10);
        flow = c / 10;
    }
    if (flow != 0) {
        res = to_str(flow) + res;
    }
    return res;
}

int Leetcode43cn::to_num(char ch) { return (int)(ch - '0'); }

char Leetcode43cn::to_str(int num) { return (char)('0' + num); }
