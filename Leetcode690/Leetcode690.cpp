//
// Created by cestl on 2018/5/3 0003.
//

#include "Leetcode690.h"

int Leetcode690::getImportance(vector<Employee *> employees, int id) {
    unordered_map<int, Employee *> pool;
    for (auto e : employees)
        pool[e->id] = e;
    return getSum(pool, id);
}

int Leetcode690::getSum2(unordered_map<int, Employee *> &pool, int id) {
    int ans = pool[id]->importance;
    for (auto e : pool[id]->subordinates)
        ans += getSum(pool, e);
    return ans;
}
int Leetcode690::getSum(unordered_map<int, Employee *> &pool, int id) {
    int ans = 0;
    queue<int> q;
    q.push(id);
    while (!q.empty()) {
        int temp = q.front();
        q.pop();
        ans += pool[temp]->importance;
        for (auto e : pool[temp]->subordinates)
            q.push(e);
    }
    return ans;
}


