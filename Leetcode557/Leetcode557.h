//
// Created by cestl on 2018/5/3 0003.
//

#ifndef LEETCODE_LEETCODE557_H
#define LEETCODE_LEETCODE557_H

#include "../config.h"

class Leetcode557 {
public:
    string reverseWords(string s);

private:
    void reverseStr(string &s, int low, int high);
};


#endif //LEETCODE_LEETCODE557_H
