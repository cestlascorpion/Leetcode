//
// Created by cestl on 2018/5/9 0009.
//

#ifndef LEETCODE_OBSERVER_H
#define LEETCODE_OBSERVER_H

#include "../config.h"

class NonCopyable {
protected:
    NonCopyable() = default;

    ~NonCopyable() = default;

    NonCopyable(const NonCopyable &) = delete;//禁止复制构造
    NonCopyable &operator=(const NonCopyable &)= delete;//禁止赋值构造
};

template<typename Func>
class Events : NonCopyable {
public:
    Events() {}

    ~Events() {}

    //注册观察者，支持右值引用
    int Connect(Func &&f) { return Assgin(f); }

    int Connect(const Func &f) { return Assgin(f); }

    //移除观察者
    void Disconnect(int key) { m_connections.erase(key); }

    //通知所有观察者
    template<typename ...Args>
    void Notify(Args &&...args) {
        for (auto &it:m_connections) {
            it.second(std::forward<Args>(args)...);
        }
    }

private:
    template<typename F>
    int Assgin(F &&f) {
        int k = m_observerId++;
        m_connections.emplace(k, std::forward<F>(f));
        return k;
    }

    int m_observerId = 0;
    std::map<int, Func> m_connections;//key->Func
};

#endif //LEETCODE_OBSERVER_H
