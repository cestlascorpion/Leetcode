#include "000.config.h"

class Solution
{
  public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        vector<int> ans(k, 0);
        unordered_map<int, int> map; //number,count
        for (auto elem : nums)
            map[elem]++;
        vector<pair<int, int>> vec; //<numbers,count>
        for (auto elem : map)
        {
            if (vec.size() < k)
            {
                vec.push_back(make_pair(elem.first, elem.second));
                if (vec.size() == k)
                    for (int i = k / 2 - 1; i >= 0; i--)
                        HeapAdjust(vec, i, k);
            }
            else
            {
                if (vec[0].second < elem.second)
                {
                    vec[0].first = elem.first;
                    vec[0].second = elem.second;
                    HeapAdjust(vec, 0, k);
                }
            }
        }
        for (int i = k - 1; i >= 0; i--)
        {
            ans[i] = vec[0].first;
            swap(vec[0], vec[i]);
            HeapAdjust(vec, 0, i);
        }
        return ans;
    }
    void HeapAdjust(vector<pair<int, int>> &vec, int root, int n)
    {
        int i = root;
        int j = 2 * i + 1;
        while (j < n)
        {
            if (j < n - 1 && vec[j].second > vec[j + 1].second)
                j = j + 1;
            if (vec[i].second < vec[j].second)
                break;
            else
            {
                swap(vec[i], vec[j]);
                i = j;
                j = 2 * i + 1;
            }
        }
    }
};
class Solution2
{
  public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> map;
        for (int num : nums)
            map[num]++;

        vector<int> res;
        // pair<first, second>: first is frequency,  second is number
        priority_queue<pair<int, int>> pq;
        for (auto it = map.begin(); it != map.end(); it++)
        {
            pq.push(make_pair(it->second, it->first));
            if (pq.size() > (int)map.size() - k)
            {
                res.push_back(pq.top().second);
                pq.pop();
            }
        }
        return res;
    }
};