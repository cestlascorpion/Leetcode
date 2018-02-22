class Solution
{
  public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> result;
        unordered_map<int, int> maps;
        for (int i = 0; i != nums.size(); i++)
        {
            if (maps.count(target - nums[i]))
            {
                result.push_back(i);
                result.push_back(maps[target - nums[i]]);
                return result;
            }
            maps[nums[i]] = i;
        }
        return result;
    }
};