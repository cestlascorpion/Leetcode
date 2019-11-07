//
// Created by Wang on 2019/11/7.
//

#include "Leetcode1200cn.h"

vector<vector<int>> Leetcode1200cn::minimumAbsDifference(vector<int> &arr) {
    sort(arr.begin(), arr.end());
    int min = arr[1] - arr[0];
    for (int i = 2; i < arr.size(); ++i) {
        if (arr[i] - arr[i - 1] < min) {
            min = arr[i] - arr[i - 1];
        }
    }
    vector<vector<int>> res;
    for (int i = 1; i < arr.size(); ++i) {
        if (arr[i] - arr[i - 1] == min) {
            res.push_back({arr[i - 1], arr[i]});
        }
    }
    return res;
}
