/*
 动态规划问题
 数组f(n)存储 遍历到num[k]时的最优结果
 改最优结果是 max(选中当前num[k]+在num[k-2]时的最优结果, 前一个的最优结果)
*/
class Solution
{
  public:
    int rob(vector<int> &nums)
    {
        const int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];
        if (n == 2)
            return max(nums[0], nums[1]);

        vector<int> f(n, 0);
        f[0] = nums[0];
        f[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++)
            f[i] = max(f[i - 2] + nums[i], f[i - 1]);
        return f[n - 1];
    }
};
class Solution
{
  public:
    int rob(vector<int> &nums)
    {
        int n = nums.size(), pre = 0, cur = 0;
        for (int i = 0; i < n; i++)
        {
            int temp = max(pre + nums[i], cur);
            pre = cur;
            cur = temp;
        }
        return cur;
    }
};
class Solution
{
  public:
    int rob(vector<int> &num)
    {
        int best0 = 0; // 表示没有选择当前houses
        int best1 = 0; // 表示选择了当前houses
        for (int i = 0; i < num.size(); i++)
        {
            int temp = best0;
            best0 = max(best0, best1); // 没有选择当前houses，那么它等于上次选择了或没选择的最大值
            best1 = temp + num[i];     // 选择了当前houses，值只能等于上次没选择的+当前houses的money
        }
        return max(best0, best1);
    }
};