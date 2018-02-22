class Solution
{
  public:
    int findUnsortedSubarray(vector<int> &nums)
    {
        vector<int> copy(nums);
        sort(copy.begin(), copy.end());
        int start = 0, end = nums.size() - 1;
        while (start < nums.size() && nums[start] == copy[start])
            start++;
        while (end > start && nums[end] == copy[end])
            end--;
        return end - start + 1;
    }
};