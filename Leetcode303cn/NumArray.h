//
// Created by Wang on 2019/11/11.
//

#ifndef LEETCODE_NUMARRAY_H
#define LEETCODE_NUMARRAY_H

#include <config.h>

class NumArrayy {
public:
    NumArrayy(vector<int> &nums) {
        int n = nums.size();
        if (n > 0) {
            vector<int> dp(n + 1);
            dp[0] = 0;
            for (int i = 1; i <= n; ++i)
                dp[i] = dp[i - 1] + nums[i - 1];
            res.swap(dp);
        }
    }

    int sumRange(int i, int j) { return res[j + 1] - res[i]; }

private:
    vector<int> res;
};

class NumArray {
public:
    NumArray(vector<int> &nums) {
        if (nums.empty()) {
            return;
        }
        begin = 0;
        end = 0;
        sum = nums[0];
        num = nums;
    }

    int sumRange(int i, int j) {
        if (i == begin && j == end) {
            return sum;
        }
        if (i < begin) {
            // + [i, begin)
            for (int j = i; j < begin; ++j) {
                sum += num[j];
            }
            begin = i;
        }
        if (i > begin) {
            // -[begin, i)
            for (int j = begin; j < i; ++j) {
                sum -= num[j];
            }
            begin = i;
        }

        if (j > end) {
            // + (end, j]
            for (int i = end + 1; i <= j; ++i) {
                sum += num[i];
            }
            end = j;
        }
        if (j < end) {
            // -(j, end]
            for (int i = j + 1; i <= end; ++i) {
                sum -= num[i];
            }
            end = j;
        }
        return sum;
    }

private:
    int begin;
    int end;
    int sum;
    vector<int> num;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */

#endif // LEETCODE_NUMARRAY_H
