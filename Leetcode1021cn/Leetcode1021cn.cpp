//
// Created by Wang on 2019/11/22.
//

#include "Leetcode1021cn.h"

string Leetcode1021cn::removeOuterParentheses(string S) {
    string res;
    stack<char> st;
    int pos = 0;
    for (int i = 0; i < S.size(); ++i) {
        if (S[i] == '(') {
            st.push(S[i]);
        } else {
            st.pop();
        }
        if (st.empty()) {
            string s = S.substr(pos, i - pos + 1);
            if (s.size() > 2) {
                res += s.substr(1, s.size() - 2);
            }
            pos = i + 1;
        }
    }
    return res;
}
