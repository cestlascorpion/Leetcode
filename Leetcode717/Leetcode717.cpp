//
// Created by cestl on 2018/5/3 0003.
//

#include "Leetcode717.h"

bool Leetcode717::isOneBitCharacter(vector<int> &bits) {
    if (bits.empty())
        return false;
    int length = bits.size();
    int index = 0;
    while (index < length) {
        if (bits[index] == '0' && index == length - 1)
            return true;
        if (bits[index] == '1')
            ++index;
        ++index;
    }
    return false;
}
