//
// Created by Wang on 2019/10/13.
//

#include "Leetcode205cn.h"

bool Leetcode205cn::isIsomorphic(string s, string t) {
    if (s.length() != t.length())
        return false;

    return Isomorphic(s, t) && Isomorphic(t, s);
}

bool Leetcode205cn::Isomorphic(string s, string t) {
    char dict[128] = {'\0'};
    for (int i = 0; i < s.length(); ++i) {
        char ch = dict[s[i]];
        if (ch == '\0') {
            dict[s[i]] = t[i];
        } else {
            if (ch != t[i]) {
                return false;
            }
        }
    }
    return true;
}

bool Leetcode205cn::isIsomorphic2(string s, string t) {
    if (s.length() != t.length())
        return false;

    for (int i = 0; i < s.size(); i++) {
        if (s.find(s[i]) != t.find(t[i]))
            return false;
    }
    return true;
}
