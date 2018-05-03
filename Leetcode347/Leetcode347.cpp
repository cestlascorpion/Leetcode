//
// Created by cestl on 2018/4/29 0029.
//

#include "Leetcode347.h"

vector<int> Leetcode347::topKFrequent(vector<int> &nums, int k) {
    vector<int> ans;
    if (nums.empty() || k < 1)
        return ans;
    unordered_map<int, int> map;//数字->频率
    for (auto item:nums) {
        map[item]++;
    }
    priority_queue<Node> pq;//频率，数字
    for (auto item:map) {
        pq.push(Node(item.second, item.first));
        if (pq.size() > k) {
            pq.pop();
        }
    }
    while (!pq.empty()) {
        ans.push_back(pq.top()._y);
        pq.pop();
    }
    return ans;
}

void Leetcode347::test347() {
    vector<int> nums = {1, 1, 1, 2, 2, 3, 3, 3, 6, 6, 6, 3, 3, 3, 2, 2, 1, 6, 7, 4, 2, 1, 3, 4, 5, 6, 2, 1, 1};
    vector<int> ans = topKFrequent(nums, 3);
    for (auto item:ans) {
        cout << item << " ";
    }
    cout << endl;
}

bool operator<(const Leetcode347::Node &a, const Leetcode347::Node &b) {
    return b._x < a._x;
}
