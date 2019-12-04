//
// Created by Wang on 2019/12/4.
//

#include "Leetcode739cn.h"

// [73,74,75,71,69,72,76,73]
// [1, 1, 4, 2, 1, 1, 0, 0]
vector<int> Leetcode739cn::dailyTemperatures(vector<int> &T) {
    vector<int> res(T.size(), 0);
    map<int, int> degree;
    for (int i = T.size() - 1; i >= 0; --i) {
        if (degree.empty()) {
            res[i] = 0;
        } else {
            auto iter = degree.upper_bound(T[i]);
            if (iter == degree.end()) {
                res[i] = 0;
            } else {
                int min = T.size();
                while (iter != degree.end()) {
                    min = std::min(min, (iter->second - i));
                    ++iter;
                }
                res[i] = min;
            }
        }
        degree[T[i]] = i;
    }
    return res;
}
vector<int> Leetcode739cn::dailyTemperatures2(vector<int> &T) {
    vector<int> res(T.size(), 0);
    stack<int> stack;
    for (int i = 0; i < T.size(); ++i) {
        while (!stack.empty() && T[i] > T[stack.top()]) {
            res[stack.top()] = i - stack.top();
            stack.pop();
        }
        stack.push(i);
    }
    return res;
}
