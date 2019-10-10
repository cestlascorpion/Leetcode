//
// Created by hans-01829 on 10/11/19.
//

#include "Leetcode1170cn.h"

vector<int> Leetcode1170cn::numSmallerByFrequency(vector<string> &queries, vector<string> &words) {
    vector<int> res;
    res.resize(queries.size());
    for (int i = 0; i < queries.size(); ++i) {
        res[i] = f(queries[i]);
    }
    vector<int> comp;
    comp.resize(words.size());
    for (int i = 0; i < words.size(); ++i) {
        comp[i] = f(words[i]);
    }
    sort(comp.begin(), comp.end());
    for (auto &r : res) {
        int num = 0;
        for (int i = comp.size() - 1; i >= 0; --i) {
            if (comp[i] > r) {
                ++num;
            } else {
                break;
            }
        }
        r = num;
    }
    return res;
}
