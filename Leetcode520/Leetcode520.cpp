//
// Created by cestl on 2018/5/2 0002.
//

#include "Leetcode520.h"

bool Leetcode520::detectCapitalUse(string word) {
    int len = word.length();
    if (len < 1)
        return false;
    if (len == 1)
        return true;

    if (word[0] >= 'A' && word[0] <= 'Z') {
        if (word[1] >= 'A' && word[1] <= 'Z') {
            for (int i = 2; i < len; i++)
                if (!(word[i] >= 'A' && word[i] <= 'Z'))
                    return false;
        } else if (word[1] >= 'a' && word[1] <= 'z') {
            for (int i = 2; i < len; i++)
                if (!(word[i] >= 'a' && word[i] <= 'z'))
                    return false;
        } else
            return false;
    } else if (word[0] >= 'a' && word[0] <= 'z') {
        for (int i = 1; i < len; i++)
            if (!(word[i] >= 'a' && word[i] <= 'z'))
                return false;
    } else
        return false;
    return true;
}
