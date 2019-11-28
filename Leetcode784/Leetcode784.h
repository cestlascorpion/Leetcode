//
// Created by cestl on 2018/5/3 0003.
//

#ifndef LEETCODE_LEETCODE784_H
#define LEETCODE_LEETCODE784_H

#include "config.h"

class Leetcode784 {
public:
    vector<string> letterCasePermutation(string S);

private:
    void helper(vector<string> &ans, string S, int i);
};


#endif //LEETCODE_LEETCODE784_H
