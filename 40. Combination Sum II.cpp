#include "0.config.h"

class Solution
{
  public:
    void combo(vector<int> &candidates, vector<vector<int>> &answer, vector<int> &result, int target, int start)
    {
        if (target == 0)
        {
            answer.push_back(result);
            return;
        }
        else
        {
            for (int i = start; i < candidates.size() && candidates[i] <= target; i++)
            {
                result.push_back(candidates[i]);
                combo(candidates, answer, result, target - candidates[i], i + 1); //不允许重复使用同一个位置的数字
                result.pop_back();
                while (i < candidates.size() - 1 && candidates[i] == candidates[i + 1]) //[1 1 2 ...] 不允许[1 2]出现两次，那么遍历完第一个1后检测到后面有相同的数字则直接跳过
                    i++;
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<vector<int>> answer;
        vector<int> result;
        sort(candidates.begin(), candidates.end());
        combo(candidates, answer, result, target, 0);
        return answer;
    }
};