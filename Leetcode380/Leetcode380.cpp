//
// Created by cestl on 2018/5/4 0004.
//

#include "Leetcode380.h"

bool Leetcode380::insert(int val) {
    if (hash.find(val) != hash.end())
        return false;
    vec.push_back(val);
    hash[val] = vec.size() - 1;
    return true;
}

bool Leetcode380::remove(int val) {
    if (hash.find(val) == hash.end())
        return false;
    //交换vec末尾元素和待删除元素，然后删除末尾元素
    //vec.back()->val原来的索引位置（hash[val])，删除val->hash[val]
    vec[hash[val]] = vec.back();
    hash[vec.back()] = hash[val];
    vec.pop_back();
    hash.erase(val);
    return true;
}

int Leetcode380::getRandom() {
    return vec[rand() % vec.size()];
}
