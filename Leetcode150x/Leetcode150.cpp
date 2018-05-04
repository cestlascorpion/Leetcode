//
// Created by hans on 18-4-23.
//

#include "Leetcode150.h"

int Leetcode150::evalRPN(vector<string> &tokens) {
    stack<int> nums;
    for (string &s:tokens) {
        if (s == "+") {
            int a = nums.top();
            nums.pop();
            int b = nums.top();
            nums.pop();
            nums.push(a + b);
        } else if (s == "-") {
            int a = nums.top();
            nums.pop();
            int b = nums.top();
            nums.pop();
            nums.push(b - a);
        } else if (s == "*") {
            int a = nums.top();
            nums.pop();
            int b = nums.top();
            nums.pop();
            nums.push(a * b);
        } else if (s == "/") {
            int a = nums.top();
            nums.pop();
            int b = nums.top();
            nums.pop();
            nums.push(b / a);
        } else nums.push(stoi(s));
    }
    return nums.top();
}
