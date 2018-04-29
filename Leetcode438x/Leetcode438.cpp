//
// Created by cestl on 2018/4/29 0029.
//

#include "Leetcode438.h"

vector<int> Leetcode438::findAnagrams(string s, string p) {
    vector<int> ans;
    if (s.empty())
        return ans;
    vector<int> map(256, 0);
    int low = 0;
    int high = 0;
    int cnt = p.size();
    int num = s.size();
    for (int i = 0; i < p.size(); ++i) {
        ++map[p[i]];
    }
    while (high < num) {
        if (map[s[high++]]-- >= 1)
            --cnt;
        if (cnt == 0)
            ans.push_back(low);
        if (high - low == p.size() && map[s[low++]]++ >= 0)
            ++cnt;
    }
    return ans;
}

vector<int> Leetcode438::findAnagrams2(string s, string p) {
    vector<int> pv(256, 0), sv(256, 0), ans;
    if (s.size() < p.size())
        return ans;

    for (int i = 0; i < p.size(); ++i)
    {
        ++pv[p[i]];
        ++sv[s[i]];
    }
    if (pv == sv) //如果相同说明[0,p.size-1]匹配成功
        ans.push_back(0);

    for (int i = p.size(); i < s.size(); ++i) {
        ++sv[s[i]];            //维护长度为 p.size-1 的滑动窗口。把新写入的元素加入匹配容器sv
        --sv[s[i - p.size()]]; //把移动窗口后，待剔除元素的计数减掉
        if (pv == sv)          //比较是否相同
            ans.push_back(i - p.size() + 1);
    }
    return ans;
}
