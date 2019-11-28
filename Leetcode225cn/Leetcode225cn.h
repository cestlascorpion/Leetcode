//
// Created by Wang on 2019/11/24.
//

#ifndef LEETCODE_LEETCODE225CN_H
#define LEETCODE_LEETCODE225CN_H

#include "config.h"

class Leetcode225cn {
public:
    /** Initialize your data structure here. */
    Leetcode225cn() {}

    /** Push element x onto stack. */
    void push(int x) {
        q1.push(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int num = q1.size() - 1;
        while(num > 0){
            q2.push(q1.front());
            q1.pop();
            --num;
        }
        int res = res = q1.front();
        // q2.push(q1.front());
        q1.pop();
        swap(q1,q2);
        return res;
    }

    /** Get the top element. */
    int top() {
        int num = q1.size() - 1;
        while(num > 0){
            q2.push(q1.front());
            q1.pop();
            --num;
        }
        int res = res = q1.front();
        q2.push(q1.front());
        q1.pop();
        swap(q1,q2);
        return res;
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty();
    }

private:
    queue<int> q1;
    queue<int> q2;
};


#endif //LEETCODE_LEETCODE225CN_H
