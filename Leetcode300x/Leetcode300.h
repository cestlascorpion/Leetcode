//
// Created by cestl on 2018/5/3 0003.
//

#ifndef LEETCODE_LEETCODE300_H
#define LEETCODE_LEETCODE300_H

#include "../config.h"

class Leetcode300 {
public:
    int lengthOfLIS(vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }

        vector<int> lis(nums.size(), 0);
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            int localMax = 0;
            // 找出当前点之前的最大上升序列长度
            for (int j = 0; j < i; ++j) {
                if (lis[j] > localMax && nums[j] <= nums[i]) {
                    localMax = lis[j];
                }
            }
            // 当前点则是该局部最大上升长度加1
            lis[i] = localMax + 1;
            // 用当前点的长度更新全局最大长度
            ans = max(ans, lis[i]);
        }
        return ans;
    }
    /*
public class Solution {
    public int longestIncreasingSubsequence(int[] nums) {
            // write your code here
            if(nums.length == 0){
                return 0;
            }
            // len表示当前最长的升序序列长度（为了方便操作tails我们减1）
            int len = 0;
            // tails[i]表示长度为i的升序序列其末尾的数字
            int[] tails = new int[nums.length];
            tails[0] = nums[0];
            // 根据三种情况更新不同升序序列的集合
            for(int i = 1; i < nums.length; i++){
                if(nums[i] < tails[0]){
                    tails[0] = nums[i];
                } else if (nums[i] >= tails[len]){
                    tails[++len] = nums[i];
                } else {
                    // 如果在中间，则二分搜索
                    tails[binarySearch(tails, 0, len, nums[i])] = nums[i];
                }
            }
            return len + 1;
        }

    private int binarySearch(int[] tails, int min, int max, int target){
            while(min <= max){
                int mid = min + (max - min) / 2;
                if(tails[mid] == target){
                    return mid;
                }
                if(tails[mid] < target){
                    min = mid + 1;
                }
                if(tails[mid] > target){
                    max = mid - 1;
                }
            }
            return min;
        }
    }
     */
};


#endif //LEETCODE_LEETCODE300_H
