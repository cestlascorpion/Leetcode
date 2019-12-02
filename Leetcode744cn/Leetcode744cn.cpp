//
// Created by Wang on 2019/12/2.
//

#include "Leetcode744cn.h"

char Leetcode744cn::nextGreatestLetter(vector<char> &letters, char target) {
    auto iter = upper_bound(letters.begin(), letters.end(), target);
    if (iter == letters.end())
        return *letters.begin();
    return *iter;
}
