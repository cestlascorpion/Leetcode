//
// Created by hans on 18-4-23.
//

#include "Sort.h"

void Sort::BubbleSort(vector<int> &nums) {
    if (nums.empty())
        return;
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = 1; j < nums.size() - i; ++j) {
            if (nums[j - 1] > nums[j])
                swap(nums[j - 1], nums[j]);
        }
    }
}

void Sort::QuickSort(vector<int> &nums) {
    if (nums.empty())
        return;
    quicksort(nums, 0, nums.size() - 1);
}

void Sort::quicksort(vector<int> &nums, int low, int high) {
    if (low < high) {
        int pos = qsortpartion(nums, low, high);
        quicksort(nums, low, pos - 1);
        quicksort(nums, pos + 1, high);
    }
}

int Sort::qsortpartion(vector<int> &nums, int low, int high) {
    int key = nums[low];
    while (low < high) {
        while (low < high && nums[high] > key)
            --high;
        nums[low] = nums[high];
        while (low < high && nums[low] <= key)
            ++low;
        nums[high] = nums[low];
    }
    nums[low] = key;
    return low;
}

void Sort::QuickSort2(vector<int> &nums) {
    if (nums.size() < 2)
        return;
    stack<pair<int, int>> s;
    pair<int, int> p(0, nums.size() - 1);
    s.push(p);
    while (!s.empty()) {
        pair<int, int> boundary(s.top().first, s.top().second);
        s.pop();
        if (boundary.first < boundary.second) {
            int pos = qsortpartion(nums, boundary.first, boundary.second);
            s.push(make_pair(boundary.first,pos-1));
            s.push(make_pair(pos+1,boundary.second));
        }
    }
}

void Sort::SelectSort(vector<int> &nums) {
    if (nums.empty())
        return;
    for (int i = 0; i < nums.size(); ++i) {
        int minpos = i;
        for (int j = i + 1; j < nums.size(); ++j) {
            if (nums[j] < nums[minpos])
                minpos = j;
        }
        swap(nums[i], nums[minpos]);
    }
}

void Sort::InsertSort(vector<int> &nums) {
    if (nums.empty())
        return;
    for (int i = 1; i < nums.size(); ++i) {
        for (int j = i - 1; j >= 0 && nums[j + 1] < nums[j]; --j) {
            swap(nums[j], nums[j + 1]);
        }
    }
}

//use d instead of 1
//add another loop to InsertSort
void Sort::ShellSort(vector<int> &nums) {
    if (nums.empty())
        return;
    for (int d = (int) (nums.size() >> 1); d > 0; d = d >> 1) {
        for (int i = d; i < nums.size(); ++i) {
            for (int j = i - d; j >= 0 && nums[j + d] < nums[j]; --j) {
                swap(nums[j], nums[j + d]);
            }
        }
    }
}

void Sort::MergeSort(vector<int> &nums) {
    if (nums.empty())
        return;
    msortpartion(nums, 0, nums.size() - 1);
}

void Sort::msortpartion(vector<int> &nums, int low, int high) {
    if (low < high) {
        int mid = (low + high) >> 1;
        msortpartion(nums, low, mid);
        msortpartion(nums, mid + 1, high);
        domerge(nums, low, mid, high);
    }
}

void Sort::domerge(vector<int> &nums, int low, int mid, int high) {
    vector<int> temp = nums;
    int i = low;
    int j = mid + 1;
    int k = low;
    while (i <= mid && j <= high) {
        if (temp[i] < temp[j])
            nums[k++] = temp[i++];
        else
            nums[k++] = temp[j++];
    }
    while (i <= mid)
        nums[k++] = temp[i++];
    while (j <= high)
        nums[k++] = temp[j++];
}

void Sort::HeapSort(vector<int> &nums) {
    if (nums.empty())
        return;
    //make heap
    for (int i = nums.size() / 2 - 1; i >= 0; --i) {
        heapdajust(nums, i, nums.size());
    }
    //heap adjust
    for (int i = nums.size() - 1; i > 0; --i) {
        swap(nums[i], nums[0]);
        heapdajust(nums, 0, i);
    }
}

void Sort::heapdajust(vector<int> &nums, int root, int n) {
    int i = root;
    int j = root * 2 + 1;
    while (j < n) {
        if (j + 1 < n && nums[j + 1] > nums[j])
            j = j + 1;
        if (nums[j] > nums[i])
            swap(nums[i], nums[j]);
        i = j;
        j = 2 * i + 1;
    }
}

void Sort::testSort() {

    vector<int> nums;

    nums = {7, 5, 6, 4, 13, 15, 7, 9, 6, 3, 5, 11, 14};
    BubbleSort(nums);
    printsortans(nums);

    nums = {7, 5, 6, 4, 13, 15, 7, 9, 6, 3, 5, 11, 14};
    QuickSort(nums);
    printsortans(nums);

    nums = {7, 5, 6, 4, 13, 15, 7, 9, 6, 3, 5, 11, 14};
    QuickSort2(nums);
    printsortans(nums);

    nums = {7, 5, 6, 4, 13, 15, 7, 9, 6, 3, 5, 11, 14};
    SelectSort(nums);
    printsortans(nums);

    nums = {7, 5, 6, 4, 13, 15, 7, 9, 6, 3, 5, 11, 14};
    InsertSort(nums);
    printsortans(nums);

    nums = {7, 5, 6, 4, 13, 15, 7, 9, 6, 3, 5, 11, 14};
    ShellSort(nums);
    printsortans(nums);

    nums = {7, 5, 6, 4, 13, 15, 7, 9, 6, 3, 5, 11, 14};
    MergeSort(nums);
    printsortans(nums);

    nums = {7, 5, 6, 4, 13, 15, 7, 9, 6, 3, 5, 11, 14};
    HeapSort(nums);
    printsortans(nums);
}

void Sort::printsortans(vector<int> &ans) {
    for (auto item : ans)
        cout << item << "\t";
    cout << endl;
}