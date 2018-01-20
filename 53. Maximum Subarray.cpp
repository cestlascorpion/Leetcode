/* 53. Maximum Subarray
 * 遍历该数组， 在遍历过程中， 将遍历到的元素依次累加起来， 当累加结果小于或等于0时， 从下一个元素开始，重新开始累加
 * 一次遍历之后， 变量res中存储的即为最大子片段的和值
 */
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        if(len < 1)
            return 0;
        
        int res = 0;
        int ans = nums.at(0);
        for(int i = 0; i < nums.size(); i ++)
        {
            res += nums.at(i);
            ans = max(ans,res);
            res = max(res, 0);      
        }
        return ans;
    }
};