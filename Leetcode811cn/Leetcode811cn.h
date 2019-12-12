//
// Created by Wang on 2019/12/12.
//

#ifndef LEETCODE_LEETCODE811CN_H
#define LEETCODE_LEETCODE811CN_H

#include "config.h"

class Leetcode811cn {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains);

    void helper(const string &str, map<string, int> &counter);
};
#endif // LEETCODE_LEETCODE811CN_H
