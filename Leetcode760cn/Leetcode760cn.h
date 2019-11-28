//
// Created by Wang on 2019/11/12.
//

#ifndef LEETCODE_LEETCODE760CN_H
#define LEETCODE_LEETCODE760CN_H

#include "config.h"

class Leetcode760cn {
public:
    vector<int> anagramMappings(vector<int> &A, vector<int> &B) {
        multimap<int, int> dict;
        for (int i = 0; i < B.size(); ++i) {
            dict.insert({B[i], i});
        }
        vector<int> res;
        for (int ele : A) {
            auto iter = dict.lower_bound(ele);
            res.push_back(iter->second);
            dict.erase(iter);
        }
        return res;
    }
};


#endif //LEETCODE_LEETCODE760CN_H
