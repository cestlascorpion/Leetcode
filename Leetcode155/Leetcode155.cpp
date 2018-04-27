//
// Created by hans on 4/27/18.
//

#include "Leetcode155.h"

Leetcode155::Leetcode155() {

}

void Leetcode155::push(int x) {
    if (s2.empty() || s2.top() >= x)
        s2.push(x);
    s1.push(x);
}

void Leetcode155::pop() {
    if (!s2.empty() && s2.top() == s1.top())
        s2.pop();
    s1.pop();
}

int Leetcode155::top() {
    return s1.top();

}

int Leetcode155::getMin() {
    return s2.top();
}
