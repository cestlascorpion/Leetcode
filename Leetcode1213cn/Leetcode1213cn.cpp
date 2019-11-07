//
// Created by Wang on 2019/11/7.
//

#include "Leetcode1213cn.h"

vector<int> Leetcode1213cn::arraysIntersection(vector<int> &arr1, vector<int> &arr2, vector<int> &arr3) {
    vector<int> ans;
    int i = 0, j = 0, k = 0;
    while (i < arr1.size() && j < arr2.size() && k < arr3.size()) {
        int max = std::max(arr1[i], std::max(arr2[j], arr3[k]));
        while (i < arr1.size() && arr1[i] < max) {
            ++i;
        }
        while (j < arr2.size() && arr2[j] < max) {
            ++j;
        }
        while (k < arr3.size() && arr3[k] < max) {
            ++k;
        }
        if (i == arr1.size() || j == arr2.size() || k == arr3.size())
            break;
        if (arr1[i] == arr2[j] && arr1[i] == arr3[k]) {
            ans.push_back(arr1[i]);
            ++i;
            ++j;
            ++k;
        }
    }
    return ans;
}
