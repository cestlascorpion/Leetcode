//
// Created by Wang on 2019/10/20.
//

#ifndef LEETCODE_LEETCODE5CN_H
#define LEETCODE_LEETCODE5CN_H

#include <config.h>

class Leetcode5cn {
public:
    string longestPalindrome(string s);

private:
    int helper(string s, int l, int r);
};

#endif // LEETCODE_LEETCODE5CN_H
