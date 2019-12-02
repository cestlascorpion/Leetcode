//
// Created by Wang on 2019/12/2.
//

#include "Leetcode599cn.h"

vector<string> Leetcode599cn::findRestaurant(vector<string> &list1, vector<string> &list2) {
    vector<string> res;
    map<string, int> dict;
    for (int i = 0; i < list1.size(); ++i) {
        dict[list1[i]] += i;
    }

    int min = INT32_MAX;
    for (int i = 0; i < list2.size(); ++i) {
        auto iter = dict.find(list2[i]);
        if (iter != dict.end()) {
            int sum = iter->second + i;
            if (sum < min) {
                min = sum;
                res.clear();
                res.push_back(list2[i]);
            } else if (sum == min) {
                res.push_back(list2[i]);
            }
        }
    }
    return res;
}
