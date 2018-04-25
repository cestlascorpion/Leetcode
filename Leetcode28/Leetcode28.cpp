//
// Created by hans on 4/25/18.
//

#include "Leetcode28.h"

int Leetcode28::strStr(string haystack, string needle) {
    if (needle.empty())
        return 0;
    if (haystack.empty() || needle.length() > haystack.length())
        return -1;
    int ans = -1;
    for (int i = 0; i <= haystack.length() - needle.length(); ++i) {
        int j = i;
        for (int k = 0; k < needle.length(); ++j, ++k) {
            if (haystack[j] != needle[k])
                break;
        }
        if (j - i == needle.length())
            return i;
    }
    return -1;
}

void Leetcode28::test28() {
    string haystack = "aaabaaa", needle = "ba";
    cout << strStr(haystack, needle) << endl;
}
