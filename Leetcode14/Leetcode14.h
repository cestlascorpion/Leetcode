//
// Created by hans on 4/25/18.
//

#ifndef LEETCODE_LEETCODE14_H
#define LEETCODE_LEETCODE14_H

#include "../config.h"

class Leetcode14 {
public:
    string longestCommonPrefix(vector<string> &strs);

    void test14();

private:
    string commonPrefix(string &a, string &b);

};


#endif //LEETCODE_LEETCODE14_H
