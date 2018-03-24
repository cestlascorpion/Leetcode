/*
对于一个长度为n的已排序数列a，若n为奇数，中位数为a[n / 2 + 1] , 
    若n为偶数，则中位数(a[n / 2] + a[n / 2 + 1]) / 2
    如果我们可以在两个数列中求出第K小的元素，便可以解决该问题
    不妨设数列A元素个数为n，数列B元素个数为m，各自升序排序，求第k小元素
    取A[k / 2] B[k / 2] 比较，
    如果 A[k / 2] > B[k / 2] 那么，所求的元素必然不在B的前k / 2个元素中(证明反证法)
    反之，必然不在A的前k / 2个元素中，于是我们可以将A或B数列的前k / 2元素删去，求剩下两个数列的
    k - k / 2小元素，于是得到了数据规模变小的同类问题，递归解决
    如果 k / 2 大于某数列个数，所求元素必然不在另一数列的前k / 2个元素中，同上操作就好。
*/
#include "0.config.h"

class Solution
{
  public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        // write your code here
        int len1 = nums1.size();
        int len2 = nums2.size();
        int len = len1 + len2;
        if (len & 1)
        {
            return findKth(nums1, 0, nums2, 0, len / 2 + 1);
        }
        return (findKth(nums1, 0, nums2, 0, len / 2) + findKth(nums1, 0, nums2, 0, len / 2 + 1)) / 2;
    }

    double findKth(vector<int> &nums1, int i1, vector<int> &nums2, int i2, int k)
    {
        if (i1 >= nums1.size())
        {
            return nums2[i2 + k - 1];
        }
        if (i2 >= nums2.size())
        {
            return nums1[i1 + k - 1];
        }
        if (k == 1)
        {
            return min(nums1[i1], nums2[i2]);
        }

        int key1 = i1 + k / 2 - 1 >= nums1.size() ? INT_MAX : nums1[i1 + k / 2 - 1];
        int key2 = i2 + k / 2 - 1 >= nums2.size() ? INT_MAX : nums2[i2 + k / 2 - 1];
        if (key1 < key2)
        {
            return findKth(nums1, i1 + k / 2, nums2, i2, k - k / 2);
        }
        else
        {
            return findKth(nums1, i1, nums2, i2 + k / 2, k - k / 2);
        }
    }
};