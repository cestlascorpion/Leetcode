//
// Created by hans on 18-4-23.
//

#ifndef LEETCODE_SORT_H
#define LEETCODE_SORT_H

#include "../config.h"

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

    void testSort();

private:
    void quicksort(vector<int> &nums, int low, int high);

    int qsortpartion(vector<int> &nums, int low, int high);

    void domerge(vector<int> &nums, int low, int mid, int high);

    void msortpartion(vector<int> &nums, int low, int high);

    void heapdajust(vector<int> &nums, int root, int n);

    void printsortans(vector<int> &ans);
};


#endif //LEETCODE_SORT_H
