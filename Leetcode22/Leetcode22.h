//
// Created by hans on 4/29/18.
//

#ifndef LEETCODE_LEETCODE22_H
#define LEETCODE_LEETCODE22_H

#include "../config.h"

class Leetcode22 {
public:
    vector<string> generateParenthesis(int n);

    void test22();

private:
    void helper(string s, int l, int r, vector<string> &ans);
};


#endif //LEETCODE_LEETCODE22_H
