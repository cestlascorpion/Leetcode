//
// Created by Wang on 2019/11/7.
//

#include "Leetcode1243cn.h"

vector<int> Leetcode1243cn::transformArray(vector<int> &arr) {
    if (arr.size() <= 2)
        return arr;
    bool changed;
    vector<int> last;
    do {
        changed = false;
        last = arr;
        for (int i = 1; i < arr.size() - 1; ++i) {
            if (last[i - 1] > arr[i] && last[i + 1] > arr[i]) {
                ++arr[i];
                changed = true;
                continue;
            }
            if (last[i - 1] < arr[i] && last[i + 1] < arr[i]) {
                --arr[i];
                changed = true;
                continue;
            }
        }
    } while (changed);
    return arr;
}
