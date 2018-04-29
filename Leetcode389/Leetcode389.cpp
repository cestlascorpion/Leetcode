//
// Created by cestl on 2018/4/29 0029.
//

#include "Leetcode389.h"

char Leetcode389::findTheDifference(string s, string t) {
    char res = 0;
    for (char c : s)
        res ^= c;
    for (char c : t)
        res ^= c;
    return res;
}
