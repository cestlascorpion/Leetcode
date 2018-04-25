//
// Created by hans on 4/25/18.
//

#include "Leetcode344.h"

string Leetcode344::reverseString(string s) {
    string ans;
    if (s.empty())
        return ans;
    for (int i = s.length() - 1; i >= 0; --i)
        ans += s[i];
    return ans;
}

void Leetcode344::test344() {
    string s = "Hello";
    cout << reverseString(s) << endl;
    s="world";
    cout << reverseString(s) << endl;
}
