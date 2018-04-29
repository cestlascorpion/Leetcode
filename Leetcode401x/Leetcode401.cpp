//
// Created by cestl on 2018/4/29 0029.
//

#include "Leetcode401.h"

vector<string> Leetcode401::readBinaryWatch(int num) {
    vector<int> chart = {1, 2, 4, 8, 1, 2, 4, 8, 16, 32};
    vector<string> ans;
    helper(ans, chart, num, 0, 0, 0, 0);
    return ans;
}

void Leetcode401::helper(vector<string> &ans, vector<int> &chart,
                         int &num, int cur, int idx, int hour, int min) {
    if (hour > 11 || min > 59)
        return;
    if (cur == num) {
        string tmp = to_string(hour) + ":" + ((min < 10) ? "0" : "") + to_string(min);
        ans.push_back(tmp);
        return;
    }
    for (int i = idx; i < chart.size(); i++) {
        if (i < 4)
            helper(ans, chart, num, cur + 1, i + 1, hour + chart[i], min);
        else
            helper(ans, chart, num, cur + 1, i + 1, hour, min + chart[i]);
    }
}
