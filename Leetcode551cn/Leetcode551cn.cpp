//
// Created by Wang on 2019/11/30.
//

#include "Leetcode551cn.h"

bool Leetcode551cn::checkRecord(string s) {
    int A = 0; // <=1
    int L = 0; // <=2
    for (const auto &ch : s) {
        switch (ch) {
        case 'A': {
            ++A;
            L = 0;
            if (A > 1) {
                return false;
            }
            break;
        }
        case 'L': {
            ++L;
            if (L > 2) {
                return false;
            }
            break;
        }
        default:
            L = 0;
        }
    }
    return true;
}
