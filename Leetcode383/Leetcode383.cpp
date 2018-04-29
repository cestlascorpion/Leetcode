//
// Created by cestl on 2018/4/29 0029.
//

#include "Leetcode383.h"

bool Leetcode383::canConstruct(string ransomNote, string magazine) {
    vector<int> hash(26, 0);
    for (auto c : magazine)
        ++hash[c - 'a'];
    for (auto c : ransomNote) {
        if (--hash[c - 'a'] < 0)
            return false;
    }
    return true;
}
