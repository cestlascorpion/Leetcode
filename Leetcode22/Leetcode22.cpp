//
// Created by hans on 4/29/18.
//

#include "Leetcode22.h"

vector<string> Leetcode22::generateParenthesis(int n) {
    vector<string> ans;
    if (n < 1)
        return ans;
    int l = n;
    int r = n;
    string s;
    helper(s, l, r, ans);
    return ans;
}

void Leetcode22::helper(string s, int l, int r, vector<string> &ans) {
    if ((l == 0 && r == 0)) {
        ans.push_back(s);
        return;
    }
    if (l > 0) {
        helper(s+"(", l - 1, r, ans);
    }
    if (r > 0 && l < r) {
        helper(s+")", l, r - 1, ans);
    }
}

void Leetcode22::test22() {
    vector<string> ans = generateParenthesis(3);
    for (auto item:ans) {
        cout << item << endl;
    }
}
