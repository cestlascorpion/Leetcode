//
// Created by Wang on 2019/12/2.
//

#ifndef LEETCODE_KTHLARGEST_H
#define LEETCODE_KTHLARGEST_H

#include "config.h"

class KthLargest {
public:
    KthLargest(int k, vector<int> &nums)
        : _k(k)
        , _pq() {
        for (const auto &num : nums) {
            _pq.push(num);
            if (_pq.size() == _k + 1) {
                _pq.pop();
            }
        }
    }

    int add(int val) {
        _pq.push(val);
        if (_pq.size() == _k + 1) {
            _pq.pop();
        }
        return _pq.top();
    }

private:
    int _k;
    priority_queue<int, vector<int>, greater<int>> _pq;
};

#endif // LEETCODE_KTHLARGEST_H
