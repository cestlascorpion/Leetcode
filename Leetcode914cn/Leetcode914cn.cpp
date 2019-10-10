//
// Created by Wang on 2019/10/13.
//

#include "Leetcode914cn.h"

bool Leetcode914cn::hasGroupsSizeX(vector<int> &deck) {
    if (deck.empty()) {
        return false;
    }
    unordered_map<int, int> map;
    for (const auto &num:deck) {
        ++map[num];
    }

    int x = map[deck[0]];
    for (const auto &pair: map) {
        x = gcd(x, pair.second);
    }
    return x >= 2;
}

int Leetcode914cn::gcd(int a, int b) {
    int r;
    while (b != 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

bool Leetcode914cn::hasGroupsSizeX2(vector<int> &deck) {
    if (deck.empty()) {
        return false;
    }
    unordered_map<int, int> map;
    for (const auto &num:deck) {
        ++map[num];
    }
    int min = INT_MAX;
    for (const auto &pair:map) {
        if (pair.second == 1) {
            return false;
        }
        min = std::min(INT_MAX, pair.second);
    }
    for (int x = 2; x <= min; ++x) {
        bool pass = true;
        for (const auto &pair:map) {
            if (pair.second % x != 0) {
                pass = false;
                break;
            }
        }
        if (pass) return true;
    }
    return false;
}
