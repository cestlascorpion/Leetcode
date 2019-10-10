//
// Created by Wang on 2019/10/13.
//

#include "Leetcode345cn.h"

string Leetcode345cn::reverseVowels(string s) {
    int low = 0;
    int high = s.size() - 1;
    while (low < high) {
        while (low < high && !isVowels(s[low]))
            ++low;
        while (low < high && !isVowels(s[high]))
            --high;
        swap(s[low], s[high]);
        ++low, --high;
    }
    return s;
}
