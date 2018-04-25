//
// Created by hans on 4/25/18.
//

#include "Leetcode8.h"

int Leetcode8::myAtoi(string str) {
    int index = 0;
    while (str[index] == ' ')
        index++;
    int flag = 1;
    if (str[index] == '-') {
        index++;
        flag = -1;
    } else if (str[index] == '+') {
        index++;
    }
    int res = 0;
    while (index < str.length()) {
        if (str[index] < '0' || str[index] > '9') {
            return flag * res;
        }
        int digit = str[index] - '0';
        if (flag == 1 && res * 10.0 + digit > INT32_MAX) {
            return INT32_MAX;
        } else if (flag == -1 && -(res * 10.0 + digit) < INT32_MIN) {
            return INT32_MIN;
        }
        res = res * 10 + digit;
        index++;
    }
    return flag * res;
}

void Leetcode8::test8() {
    string s1 = " -042";
    cout << myAtoi(s1) << endl;
    string s2 = "+42 and word";
    cout << myAtoi(s2) << endl;
    string s3 = "-0191283472332";
    cout << myAtoi(s3) << endl;
}
