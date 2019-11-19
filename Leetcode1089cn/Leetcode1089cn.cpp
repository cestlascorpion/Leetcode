//
// Created by Wang on 2019/11/19.
//

#include "Leetcode1089cn.h"

void Leetcode1089cn::duplicateZeros(vector<int> &arr) {
    int last = 0;
    int resize = 0;
    int size = arr.size();
    for (int i = 0; i < size; ++i) {
        if (arr[i] == 0) {
            resize += 2;
        } else {
            ++resize;
        }
        if (resize >= size) {
            last = i;
            break;
        }
    }
    while (last >= 0) {
        if (arr[last] != 0) {
            arr[resize - 1] = arr[last];
            --resize;
            --last;
        } else {
            if (resize <= size) {
                arr[resize - 1] = 0;
            }
            arr[resize - 2] = 0;
            resize -= 2;
            --last;
        }
    }
}
