//
// Created by hans on 4/28/18.
//

#ifndef LEETCODE_LEETCODE17_H
#define LEETCODE_LEETCODE17_H

#include <config.h>

class Leetcode17 {
public:
    vector<string> letterCombinations(string digits);

    void test17();

private:
    void helper(string digits, int index, map<char, string> &dict, vector<string> &ans);
};


#endif //LEETCODE_LEETCODE17_H
