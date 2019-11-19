//
// Created by Wang on 2019/11/19.
//

#include "Leetcode1122cn.h"

vector<int> Leetcode1122cn::relativeSortArray(vector<int> &arr1, vector<int> &arr2) {
    unordered_map<int, int> dict;
    for (int i = 0; i < arr2.size(); ++i) {
        dict[arr2[i]] = i;
    }
    auto cmp = [&](int a, int b) -> bool {
        auto ater = dict.find(a);
        auto bter = dict.find(b);
        if (ater != dict.end() && bter != dict.end()) {
            return ater->second < bter->second;
        } else if (ater == dict.end() && bter == dict.end()) {
            return a < b;
        } else return (ater != dict.end() && bter == dict.end());
    };

    sort(arr1.begin(), arr1.end(), cmp);
    return arr1;
}
