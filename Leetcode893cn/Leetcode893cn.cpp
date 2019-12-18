//
// Created by Wang on 2019/12/18.
//

#include "Leetcode893cn.h"

int Leetcode893cn::numSpecialEquivGroups(vector<string> &A) {
    if (A.empty())
        return 0;

    for (auto &s : A) {
        adjust(s);
    }
    sort(A.begin(), A.end());
    set<string> s(A.begin(), A.end());
    return s.size();
}

void Leetcode893cn::adjust(string &s) {
    string odd;
    string even;
    for (int i = 0; i < s.size(); ++i) {
        if (i % 2 == 0) {
            odd.push_back(s[i]);
        } else {
            even.push_back(s[i]);
        }
    }
    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end());
    int x = 0;
    int y = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (i % 2 == 0) {
            s[i] = odd[x++];
        } else {
            s[i] = even[y++];
        }
    }
}
