//
// Created by Wang on 2019/12/3.
//

#ifndef LEETCODE_LEETCODE716CN_H
#define LEETCODE_LEETCODE716CN_H

#include "config.h"

class MaxStack {
public:
    /** initialize your data structure here. */
    MaxStack() {}

    void push(int x) {
        s1.push(x);
        if (s2.empty()) {
            s2.push(x);
        } else {
            if (s2.top() <= x) {
                s2.push(x);
            }
        }
    }

    int pop() {
        if (!s2.empty() && s1.top() == s2.top()) {
            s2.pop();
        }
        int res = s1.top();
        s1.pop();
        return res;
    }

    int top() { return s1.top(); }

    int peekMax() { return s2.top(); }

    int popMax() {
        while (!s1.empty() && s1.top() != s2.top()) {
            tmp.push(s1.top());
            s1.pop();
        }
        int res = s2.top();
        s1.pop();
        s2.pop();
        while (!tmp.empty()) {
            s1.push(tmp.top());
            if (s2.empty()) {
                s2.push(tmp.top());
            } else {
                if (s2.top() <= tmp.top()) {
                    s2.push(tmp.top());
                }
            }
            tmp.pop();
        }
        return res;
    }

private:
    stack<int> s1; // all
    stack<int> s2; // max;
    stack<int> tmp;
};

#endif // LEETCODE_LEETCODE716CN_H
