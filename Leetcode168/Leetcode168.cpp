//
// Created by cestl on 2018/4/29 0029.
//

#include "Leetcode168.h"

string Leetcode168::convertToTitle(int n) {
    string ans;
    stack<char> s;
    while (n) {
        int d = (n - 1) % 26;
        s.push(d + 'A');
        n = (n - 1) / 26;
    }
    while (!s.empty()) {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}
