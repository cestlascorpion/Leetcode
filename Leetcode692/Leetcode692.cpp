//
// Created by cestl on 2018/6/7 0007.
//

#include "Leetcode692.h"

vector<string> Leetcode692::topKFrequent(vector<string> &words, int k) {
    vector<string> ans;
    if (words.empty())
        return ans;

    unordered_map<string, int> umap;
    for (auto &word:words) {
        ++umap[word];
    }

    if (umap.empty() || umap.size() < k)
        return ans;

    auto cmp = [](const pair<string, int> &a, const pair<string, int> &b) {
        return a.second == b.second ? a.first < b.first : a.second > b.second;
    };

    priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp)> pq(cmp);
    for (auto &item:umap) {
        pq.emplace(item.first, item.second);
        if (pq.size() > k)
            pq.pop();
    }
    while (!pq.empty()) {
        ans.push_back(pq.top().first);
        pq.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

void Leetcode692::test692() {
    vector<string> words = {"the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"};
    auto ans = topKFrequent(words, 2);
    for (const auto &item:ans) {
        cout << item << " ";
    }
}