//
// Created by cestl on 2018/5/9 0009.
//

#ifndef LEETCODE_ORDER_H
#define LEETCODE_ORDER_H

#include "../config.h"

/*
    template<class F, class ... Args, class= typename std::enable_if<!std::is_member_function_pointer<F>::value>::type>
    void Warp(F &&f, Args &&... args) {
        return f(std::forward<Args>(args)...);
    }
    template<class R, class C, class... DArgs, class P, class... Args>
    void Warp(R(C::*f)(DArgs...), P &&p, Args &&... args) {
        return (*p.*f)(std::forward<Args>(args)...);
    }
 */
template<typename R=void>
class Order {
private:
    std::function<R()> m_f;
public:
    //接受可调用对象的函数包装器
    template<class F, class ... Args, class= typename std::enable_if<!std::is_member_function_pointer<F>::value>::type>
    void Warp(F &&f, Args &&... args) {
        m_f = [&] { return f(args...); };
    }

    //接受常量成员函数的函数包装器
    template<class R, class C, class... DArgs, class P, class... Args>
    void Warp(R(C::*f)(DArgs...), P &&p, Args &&... args) {
        m_f = [&, f] { return (*p.*f)(args...); }
    }

    R Excecute() {
        return m_f();
    }
};


#endif //LEETCODE_ORDER_H
