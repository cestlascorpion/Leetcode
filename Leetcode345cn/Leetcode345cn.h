//
// Created by Wang on 2019/10/13.
//

#ifndef LEETCODE_LEETCODE345CN_H
#define LEETCODE_LEETCODE345CN_H

#include "config.h"

class Leetcode345cn {
public:
    string reverseVowels(string s);

    bool isVowels(char ch) {
        return vowels.count(ch) != 0;
    }

private:
    const set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
};


#endif //LEETCODE_LEETCODE345CN_H
