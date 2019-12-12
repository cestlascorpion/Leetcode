//
// Created by Wang on 2019/12/12.
//

#include "Leetcode860cn.h"

bool Leetcode860cn::lemonadeChange(vector<int> &bills) {
    int five = 0;
    int ten = 0;
    for (const auto &bill : bills) {
        switch (bill) {
        case 5:
            ++five;
            break;
        case 10: {
            if (five == 0) {
                return false;
            }
            --five;
            ++ten;
            break;
        }
        case 20: {
            if (ten > 0) {
                --ten;
                if (five == 0) {
                    return false;
                } else {
                    --five;
                }
            } else {
                if (five < 3) {
                    return false;
                } else {
                    five -= 3;
                }
            }
            break;
        }
        default:
            break;
        }
    }
    return true;
}
