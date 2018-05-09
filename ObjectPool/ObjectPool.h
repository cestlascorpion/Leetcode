//
// Created by cestl on 2018/5/9 0009.
//

#ifndef LEETCODE_OBJECTPOOL_H
#define LEETCODE_OBJECTPOOL_H

#include "../config.h"

class NonCopyable {
protected:
    NonCopyable() = default;

    ~NonCopyable() = default;

    NonCopyable(const NonCopyable &) = delete;//禁止复制构造

    NonCopyable &operator=(const NonCopyable &)= delete;//禁止赋值构造
};

const int MaxObjectNum = 10;

template<typename T>
class ObjectPool : private NonCopyable {
    template<typename... Args>
    using Constructor = std::function<std::shared_ptr<T>(Args...)>;
public:
    template<typename ...Args>
    void Init(size_t num, Args &&...args) {
        if (num <= 0 || num > MaxObjectNum)
            throw std::logic_error("object num out of range");
        auto constructName = typeid(Constructor<Args...>).name();
        for (size_t i = 0; i < num; ++i) {
            m_object_map.emplace(constructName,
                                 shared_ptr<T>(new T(std::forward<Args>(args)...), [this, constructName](T *p) {
                                     m_object_map.emplace(std::move(constructName), std::shared_ptr<T>(p));
                                 }));
        }
    }

    template<typename ...Args>
    std::shared_ptr<T> Get() {
        string constructName = typeid(Constructor<Args...>).name();

        auto range = m_object_map.equal_range(constructName);
        for (auto it = range.first; it != range.second; ++it) {
            auto ptr = it->second;
            m_object_map.erase(it);
            return ptr;
        }
        return nullptr;
    }

private:
    multimap<string, std::shared_ptr<T>> m_object_map;
};


#endif //LEETCODE_OBJECTPOOL_H
