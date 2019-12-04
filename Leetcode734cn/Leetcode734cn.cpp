//
// Created by Wang on 2019/12/4.
//

#include "Leetcode734cn.h"

bool Leetcode734cn::areSentencesSimilar(vector<string> &words1, vector<string> &words2, vector<vector<string>> &pairs) {
    set<pair<string, string>> dict;
    for (const auto & pair : pairs) {
        dict.insert({pair[0], pair[1]});
    }
    if (words1.size() != words2.size())
        return false;

    for (int i = 0; i < words1.size(); ++i) {
        if (words1[i] == words2[i])
            continue;
        if (dict.count({words1[i], words2[i]}) == 0 && dict.count({words2[i], words1[i]}) == 0) {
            return false;
        }
    }
    return true;
}
