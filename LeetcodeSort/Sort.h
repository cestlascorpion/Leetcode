//
// Created by hans on 18-4-23.
//

#ifndef LEETCODE_SORT_H
#define LEETCODE_SORT_H

#include "config.h"

using namespace std;

class Sort {
public:
    void BubbleSort(vector<int> &nums);

    void QuickSort(vector<int> &nums);

    void QuickSort2(vector<int> &nums);

    void QuickSort4List(ListNode *head);

    void SelectSort(vector<int> &nums);

    void InsertSort(vector<int> &nums);

    void ShellSort(vector<int> &nums);

    void MergeSort(vector<int> &nums);

    void HeapSort(vector<int> &nums);

    void TestSort();

private:
    void QuickSortImpl(vector<int> &nums, int low, int high);

    int QsortPartition(vector<int> &nums, int low, int high);

    void MergeImpl(vector<int> &nums, int low, int mid, int high);

    void MsortPartition(vector<int> &nums, int low, int high);

    void HeapAdjust(vector<int> &nums, int root, int n);

    void PrintSortAns(vector<int> &ans);
};


#endif //LEETCODE_SORT_H
