//
// Created by cestl on 2018/4/29 0029.
//

#include "Leetcode347.h"

vector<int> Leetcode347::topKFrequent(vector<int> &nums, int k) {
    vector<int> ans;
    if (nums.empty())
        return ans;
    unordered_map<int, int> m;//数字，出现的次数
    for (int num : nums)
        m[num]++;

    priority_queue<pair<int, int>> pq;//出现的次数，数字
    for (auto item : m) {
        pq.push(make_pair(item.second, item.first));
        if (pq.size() > (int) m.size() - k) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
    }
    return ans;
}
