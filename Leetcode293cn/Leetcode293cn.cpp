//
// Created by Wang on 2019/11/11.
//

#include "Leetcode293cn.h"

vector<string> Leetcode293cn::generatePossibleNextMoves(string s) {
    vector<string> ans;
    if (s.empty()) {
        return ans;
    }

    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '+' && i + 1 < s.size() && s[i + 1] == '+') {
            string tmp = s;
            tmp[i] = '-';
            tmp[i + 1] = '-';
            ans.push_back(tmp);
        }
    }

    return ans;
}
