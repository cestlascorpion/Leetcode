class Solution {
public:
    void combo(vector<vector<int>>& ret, vector<int>& candidates, int target, int start, vector<int>& result){
      if(target < 0)
      {
        return;
      }
      else if(target == 0)//说明当前组合有效
      {
        ret.push_back(result);
        return;
      }
      else
      {
        for(int i = start; i < candidates.size()&&candidates[i]<=target; i ++)
        {
          result.push_back(candidates[i]);
          combo(ret, candidates, target - candidates[i], i, result);//还在递归中，start没有增加，所以可以重复选择 i（start for next）没有向前移动
          result.pop_back();//result中最后一个数字的加入没有满足条件的组合，pop最后一个数字，选择下一个candidates[i+1]
        }

      }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        vector<int> result;
        sort(candidates.begin(),candidates.end());
        combo(ret, candidates, target, 0, result);
        return ret;
    }
};