//
// Created by Wang on 2019/10/21.
//

#include "Leetcode252cn.h"

bool Leetcode252cn::canAttendMeetings(vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end());
    for (int i = 1; i < intervals.size(); ++i) {
        if (intervals[i - 1][1] > intervals[i][0]) {
            return false;
        }
    }
    return true;
}
