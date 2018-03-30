#include "0. config.h"

class Solution
{
  public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        int fromBegin = 1;
        int fromLast = 1;
        vector<int> res(n, 1);

        for (int i = 0; i < n; i++)
        {
            res[i] *= fromBegin;
            fromBegin *= nums[i];
            res[n - 1 - i] *= fromLast;
            fromLast *= nums[n - 1 - i];
        }
        return res;
    }
};
class Solution2
{
  public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int length = nums.size();
        vector<int> left(length, 1);
        int le = 1;
        int re = 1;
        for (int i = 1; i <= length - 1; i++)
            left[i] = nums[i - 1] * left[i - 1];

        vector<int> right(length, 1);
        for (int i = length - 2; i >= 0; i--)
            right[i] = nums[i + 1] * right[i + 1];
        for (int i = 0; i < length; i++)
            left[i] = left[i] * right[i];
        return left;
    }
};