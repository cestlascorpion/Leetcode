#include "000.config.h"

class Solution
{
  public:
    int findTargetSumWays(vector<int> &nums, int S)
    {
        int numsum = accumulate(nums.begin(), nums.end(), 0); //a+b+c
        if (numsum < S)                                       //a+b-c<a+b+c
            return 0;
        if ((S + numsum) % 2 != 0) //a+b+c+a+b-c = 2(a+b)
            return 0;
        int target = (S + numsum) / 2; //a+b

        vector<int> dp(target + 1, 0); //找到和为target的一个集合
        dp[0] = 1;                     //dp[i]表示子集合元素之和等于当前目标值的方案个数, 当前目标值等于减去当前元素值
        for (auto num : nums)
            for (int v = target; v >= num; v--)
                dp[v] += dp[v - num];
        return dp.back();
    }
};

class Solution2
{
  public:
    int findTargetSumWays(vector<int> &nums, int S)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int target = sum - S; //选注若干数字，其和的2倍=target
        int ans = 0;
        helper(nums, target, 0, 0, nums.size() - 1, ans);
        return ans;
    }
    void helper(vector<int> &nums, int target, int cur, int begin, int end, int &ans)
    {
        if (cur == target)
            ans++; //避免后面有0
        if (cur > target || begin > end)
            return;
        for (int i = begin; i <= end; i++)
        {
            cur += 2 * nums[i];
            helper(nums, target, cur, i + 1, end, ans);
            cur -= 2 * nums[i];
        }
    }
};
class Solution3
{
  public:
    int findTargetSumWays(vector<int> &nums, int S)
    {
        int ans = 0;
        helper(nums, S, 0, 0, nums.size() - 1, ans);
        return ans;
    }
    void helper(vector<int> &nums, const int &S, int cur, int begin, int end, int &ans)
    {
        if (begin > end)
        {
            cout << cur << endl;
            if (S == cur)
                ans++;
            return;
        }
        else
        {
            helper(nums, S, cur + nums[begin], begin + 1, end, ans);
            helper(nums, S, cur - nums[begin], begin + 1, end, ans);
        }
    }
};