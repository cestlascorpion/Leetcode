#include "0.config.h"
// Employee info
class Employee
{
  public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};

class Solution
{
  public:
    int getImportance(vector<Employee *> employees, int id)
    {
        unordered_map<int, Employee *> pool;
        for (auto e : employees)
            pool[e->id] = e;
        return getSum(pool, id);
    }

    int getSum2(unordered_map<int, Employee *> &pool, int id)
    {
        int ans = pool[id]->importance;
        for (auto e : pool[id]->subordinates)
            ans += getSum(pool, e);
        return ans;
    }
    int getSum(unordered_map<int, Employee *> &pool, int id)
    {
        int ans = 0;
        queue<int> q;
        q.push(id);
        while (!q.empty())
        {
            int temp = q.front();
            q.pop();
            ans += pool[temp]->importance;
            for (auto e : pool[temp]->subordinates)
                q.push(e);
        }
        return ans;
    }
};