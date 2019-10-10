//
// Created by Wang on 2019/10/14.
//

#include "Leetcode1cn.h"

vector<int> Leetcode1cn::twoSum(vector<int> &nums, int target) {
    int lo = 0;
    int hi = nums.size()-1;
    while(lo<hi){
        int sum = nums[lo]+nums[hi];
        if(sum == target){
            return {lo,hi};
        }
        if(sum>target){
            --hi;
        }else{
            ++lo;
        }
    }
    return {0,0};
}
