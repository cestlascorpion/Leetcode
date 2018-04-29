//
// Created by cestl on 2018/4/29 0029.
//

#include "Leetcode406.h"

vector<pair<int, int>> Leetcode406::reconstructQueue(vector<pair<int, int>> &people) {
    vector<pair<int, int>> ans;
    ans.clear();
    sort(people.begin(), people.end(), cmp);
    for (auto i : people)
        //此时前面的人一定都比后面的高所以他们的k就是他们应该在的位置
        ans.insert(ans.begin() + i.second, i);
    return ans;
}

bool Leetcode406::cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first)
        return a.second < b.second;
    return a.first > b.first;
}

void Leetcode406::test406() {
    vector<pair<int, int>> people = {{7, 0},
                                     {4, 4},
                                     {7, 1},
                                     {5, 0},
                                     {6, 1},
                                     {5, 2}};
    vector<pair<int, int>> ans = reconstructQueue(people);
    for (auto item:ans) {
        cout << item.first << "," << item.second << endl;
    }

}
