//
// Created by Wang on 2019/12/8.
//

#ifndef LEETCODE_LEETCODE1114CN_H
#define LEETCODE_LEETCODE1114CN_H

#include "config.h"

class Leetcode1114cn {
public:
    Leetcode1114cn():_counter(1) {}

    void first(function<void()> printFirst) {
        lock_guard<mutex> lk(_lock);
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        ++_counter;
        _first.notify_one();
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> lk(_lock);
        _first.wait(lk, [this]() { return _counter == 2; });
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        ++_counter;
        _second.notify_one();
    }

    void third(function<void()> printThird) {
        unique_lock<mutex> lk(_lock);
        _second.wait(lk, [this]() { return _counter == 3; });
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }

private:
    mutex _lock;
    condition_variable _first;
    condition_variable _second;
    int _counter;
};

#endif // LEETCODE_LEETCODE1114CN_H
