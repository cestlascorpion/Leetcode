//
// Created by Wang on 2019/11/22.
//

#include "Leetcode1119cn.h"

string Leetcode1119cn::removeVowels(string S) {
    int i = 0;
    int j = 0;
    while (true) {
        while (j < S.size() && vowel(S[j])) {
            ++j;
        }
        if (j == S.size()) {
            break;
        }
        S[i] = S[j];
        ++i;
        ++j;
    }
    S.resize(i);
    return S;
}

bool Leetcode1119cn::vowel(char &ch) {
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}
