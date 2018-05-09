//
// Created by cestl on 2018/5/9 0009.
//

#ifndef LEETCODE_VISITOR_H
#define LEETCODE_VISITOR_H

#include "../config.h"

template<typename ...Types>
class Visitor;

template<typename T, typename ...Types>
class Visitor<T, Types...> : Visitor<Types...> {
public:
    using Visitor<Types...>::Visit;

    virtual void Visit(const T &)=0;
};

template<typename T>
class Visitor<T> {
public:
    virtual void Visit(const T &)=0;
};

#endif //LEETCODE_VISITOR_H
