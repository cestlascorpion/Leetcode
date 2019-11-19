//
// Created by Wang on 2019/11/21.
//

#include "Leetcode163cn.h"

vector<string> Leetcode163cn::findMissingRanges(vector<int> &nums, int lower, int upper) {
    vector<string> res;
    int begin = lower;
    for (const auto &num : nums) {
        int end = num - 1;
        if (begin == end) {
            string str = to_string(begin);
            res.emplace_back(move(str));
        } else if (begin < end) {
            string str = to_string(begin) + "->" + to_string(end);
            res.emplace_back(move(str));
        }
        begin = num + 1;
    }
    if (begin == upper) {
        string str = to_string(begin);
        res.emplace_back(move(str));
    } else if (begin < upper) {
        string str = to_string(begin) + "->" + to_string(upper);
        res.emplace_back(move(str));
    }
    return res;
}
