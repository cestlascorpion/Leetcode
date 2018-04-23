#include "000.config.h"

class Solution
{
  public:
    int leastInterval(vector<char> &tasks, int n)
    {
        unordered_map<char, int> m;
        for (auto ch : tasks)
            m[ch]++;
        priority_queue<pair<int, char>> pq;
        for (auto e : m)
            pq.push(make_pair(e.second, e.first));

        int ans = 0;
        int cycle = n + 1;
        while (!pq.empty())
        {
            int time = 0;
            vector<pair<int, char>> temp;
            for (int i = 0; i < cycle; i++)
                if (!pq.empty())
                {
                    temp.push_back(pq.top());
                    pq.pop();
                    time++;
                }

            for (auto t : temp)
                if (t.first > 1)
                {
                    t.first--;
                    pq.push(t);
                }
            ans += !pq.empty() ? cycle : time;
        }
        return ans;
    }
};
class Solution2
{
  public:
    int leastInterval(vector<char> &tasks, int n)
    {
        vector<int> helper(26, 0);
        for (auto ch : tasks)
            helper[ch - 'A']++;
        sort(helper.begin(), helper.end());
        int i = 25;
        while (i >= 0 && helper[25] == helper[i])
            i--;
        return max((helper[25] - 1) * (n + 1) + (25 - i), (int)tasks.size());
    }
};