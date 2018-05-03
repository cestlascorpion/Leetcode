//
// Created by cestl on 2018/5/3 0003.
//

#include "Leetcode771.h"

int Leetcode771::numJewelsInStones(string J, string S) {
    if (J.empty() || S.empty())
        return 0;

    map<char, int> jmap;
    int ans = 0;

    for (int i = 0; i < J.length(); i++)
        jmap[J[i]] = i;

    for (int i = 0; i < S.length(); i++) {
        if (jmap.find(S[i]) != jmap.end())
            ans++;
    }
    return ans;
}
