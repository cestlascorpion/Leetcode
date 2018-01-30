/*
常见的排序算法有：插入 希尔  冒泡  快速  选择 堆排序 归并  基数
*/
void BubbleSortR(vector<int>& nums)
{
    int len = nums.size();
    for(int i = 0; i < len - 1; i++)//一共进行len-1次
    {
        for(int j = 1; j< len - i)
        {
            if(nums[j] < nums[j-1])
            {
                swap(nums[j],nums[j-1]);//每次姜一个最大的数字移动到最右侧
            }
        }
    }
}
void BubbleSortL(vector<int>& nums)
{
    int len = nums.size();
    for(int i = 0; i < len - 1; i++)
    {
        for(int j = n - i)
    }
}