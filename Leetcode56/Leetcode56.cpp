//
// Created by cestl on 2018/5/3 0003.
//

#include "Leetcode56.h"

vector<Interval> Leetcode56::merge(vector<Interval> &intervals) {
    if (intervals.size() <= 1)
        return intervals;

    vector<Interval> ans;
    sort(intervals.begin(), intervals.end(),
         [](Interval &a, Interval &b) -> bool { return a.start == b.start ? a.end < b.end : a.start < b.start; });
    for (int i = 1; i < intervals.size(); ++i) {
        if (intervals[i - 1].end < intervals[i].start) {
            ans.push_back(intervals[i - 1]);
        } else {
            int end = max(intervals[i - 1].end, intervals[i].end);
            intervals[i - 1].end = end;
            intervals[i] = intervals[i - 1];
        }
        if (i == intervals.size() - 1)
            ans.push_back(intervals[i]);
    }
    return ans;
}

void Leetcode56::test56() {
    vector<Interval> intervals = {{0, 4},
                                  {2, 3},
                                  {2, 8}};
    vector<Interval> ans = merge(intervals);
    for (auto item:ans) {
        cout << item.start << "-" << item.end << endl;
    }
}
