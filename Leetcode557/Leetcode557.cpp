//
// Created by cestl on 2018/5/3 0003.
//

#include "Leetcode557.h"

string Leetcode557::reverseWords(string s) {
    if (s.empty())
        return s;
    int low = 0;
    int high = 0;
    int n = s.length() - 1;
    while (low <= n && high <= n) {
        while (high <= n && s[high] != ' ')
            ++high;
        //high->' ' or >n
        if (high > n)
            reverseStr(s, low, n);
        else
            reverseStr(s, low, high - 1);
        while (high <= n && s[high] == ' ') {
            ++high;
        }
        low = high;
    }
    return s;
}

void Leetcode557::reverseStr(string& s, int low, int high) {
    while (low < high)
        swap(s[low++], s[high--]);
}
