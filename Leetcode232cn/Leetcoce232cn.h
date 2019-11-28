//
// Created by Wang on 2019/11/24.
//

#ifndef LEETCODE_LEETCOCE232CN_H
#define LEETCODE_LEETCOCE232CN_H

#include "config.h"

class Leetcoce232cn {
public:
    /** Initialize your data structure here. */
    Leetcoce232cn() {}

    /** Push element x to the back of queue. */
    void push(int x) {
        s1.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int res = s2.top();
        s2.pop();
        return res;
    }

    /** Get the front element. */
    int peek() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int res = s2.top();
        return res;
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.empty() && s2.empty();
    }

private:
    stack<int> s1;
    stack<int> s2;
};


#endif //LEETCODE_LEETCOCE232CN_H
