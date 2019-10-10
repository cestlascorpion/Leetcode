//
// Created by Wang on 2019/10/13.
//

#include "Leetcode20cn.h"

bool Leetcode20cn::isValid(string s) {
    stack<char> st;
    for (const auto &ch:s) {
        if (ch == '(' || ch == '[' || ch == '{') {
            st.push(ch);
        } else {
            switch (ch) {
                case ')': {
                    if (st.empty() || st.top() != '(') {
                        return false;
                    }
                    st.pop();
                    break;
                }
                case ']': {
                    if (st.empty() || st.top() != '[') {
                        return false;
                    }
                    st.pop();
                    break;
                }
                case '}': {
                    if (st.empty() || st.top() != '{') {
                        return false;
                    }
                    st.pop();
                    break;
                }
                default:
                    return false;
            }
        }
    }
    return st.empty();
}
