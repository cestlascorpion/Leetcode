//
// Created by cestl on 2018/5/3 0003.
//

#include "Leetcode541.h"

string Leetcode541::reverseStr(string s, int k) {
    if (s.empty() || k <= 0)
        return s;
    int low = 0;
    int high = 0;
    while (low <= s.length() - 1 && high <= s.length() - 1) {
        high = low + k - 1;
        if (low <= s.length() - 1 && high <= s.length() - 1)
            reverseStr(s, low, high);
        else if (low <= s.length() - 1 && high > s.length() - 1)
            reverseStr(s, low, s.length() - 1);
        low = high + k + 1;
        high = low;
    }
    return s;
}

void Leetcode541::reverseStr(string s, int low, int high) {
    while (low < high)
        swap(s[low++], s[high--]);
}
