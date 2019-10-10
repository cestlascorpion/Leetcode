//
// Created by Wang on 2019/10/10.
//

#include "Leetcode1189cn.h"

int Leetcode1189cn::maxNumberOfBalloons(string text) {
    // balloon
    vector<unsigned> dict;
    dict.resize(5, 0);
    for (const auto &ch:text) {
        switch (ch) {
            case 'b': {
                ++dict[0];
                break;
            }
            case 'a': {
                ++dict[1];
                break;
            }
            case 'l': {
                ++dict[2];
                break;
            }
            case 'o': {
                ++dict[3];
                break;
            }
            case 'n': {
                ++dict[4];
                break;
            }
        }
    }
    dict[2] = dict[2] / 2;
    dict[3] = dict[3] / 2;
    unsigned res = dict[0];
    for (int i = 1; i < 5; ++i) {
        res = std::min(res, dict[i]);
    }
    return (int)res;
}
