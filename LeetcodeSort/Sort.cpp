 bnvn//
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
    QuickSortImpl(nums, 0, nums.size() - 1);
}

void Sort::QuickSortImpl(vector<int> &nums, int low, int high) {
    if (low < high) {
        int pos = QsortPartition(nums, low, high);
        QuickSortImpl(nums, low, pos - 1);
        QuickSortImpl(nums, pos + 1, high);
    }
}

int Sort::QsortPartition(vector<int> &nums, int low, int high) {
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
            int pos = QsortPartition(nums, boundary.first, boundary.second);
            s.push(make_pair(boundary.first, pos - 1));
            s.push(make_pair(pos + 1, boundary.second));
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
    for (int d = nums.size() / 2; d > 0; d = d / 2) {
        for (int i = d; i < nums.size(); ++i) {
            for (int j = i - d; j >= 0 && nums[j + d] < nums[j]; j = j - d) {
                swap(nums[j], nums[j + d]);
            }
        }
    }
}

void Sort::MergeSort(vector<int> &nums) {
    if (nums.empty())
        return;
    MsortPartition(nums, 0, nums.size() - 1);
}

void Sort::MsortPartition(vector<int> &nums, int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        MsortPartition(nums, low, mid);
        MsortPartition(nums, mid + 1, high);
        MergeImpl(nums, low, mid, high);
    }
}

void Sort::MergeImpl(vector<int> &nums, int low, int mid, int high) {
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
        HeapAdjust(nums, i, nums.size());
    }
    //heap adjust
    for (int i = nums.size() - 1; i > 0; --i) {
        swap(nums[i], nums[0]);
        HeapAdjust(nums, 0, i);
    }
}

void Sort::HeapAdjust(vector<int> &nums, int root, int n) {
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

void Sort::TestSort() {

    vector<int> nums;

    nums = {7, 5, 6, 4, 13, 15, 7, 9, 6, 3, 5, 11, 14};
    BubbleSort(nums);
    PrintSortAns(nums);

    nums = {7, 5, 6, 4, 13, 15, 7, 9, 6, 3, 5, 11, 14};
    QuickSort(nums);
    PrintSortAns(nums);

    nums = {7, 5, 6, 4, 13, 15, 7, 9, 6, 3, 5, 11, 14};
    QuickSort2(nums);
    PrintSortAns(nums);

    nums = {7, 5, 6, 4, 13, 15, 7, 9, 6, 3, 5, 11, 14};
    SelectSort(nums);
    PrintSortAns(nums);

    nums = {7, 5, 6, 4, 13, 15, 7, 9, 6, 3, 5, 11, 14};
    InsertSort(nums);
    PrintSortAns(nums);

    nums = {7, 5, 6, 4, 13, 15, 7, 9, 6, 3, 5, 11, 14};
    ShellSort(nums);
    PrintSortAns(nums);

    nums = {7, 5, 6, 4, 13, 15, 7, 9, 6, 3, 5, 11, 14};
    MergeSort(nums);
    PrintSortAns(nums);

    nums = {7, 5, 6, 4, 13, 15, 7, 9, 6, 3, 5, 11, 14};
    HeapSort(nums);
    PrintSortAns(nums);

    ListNode p1(7);
    ListNode p2(5);
    ListNode p3(6);
    ListNode p4(4);
    ListNode p5(13);
    ListNode p6(15);
    ListNode p7(7);
    ListNode p8(9);
    ListNode p9(6);
    ListNode p10(3);
    ListNode p11(5);
    ListNode p12(11);
    ListNode p13(14);

    p1.next = &p2;
    p2.next = &p3;
    p3.next = &p4;
    p4.next = &p5;
    p5.next = &p6;
    p6.next = &p7;
    p7.next = &p8;
    p8.next = &p9;
    p9.next = &p10;
    p10.next = &p11;
    p11.next = &p12;
    p12.next = &p13;

    QuickSort4List(&p1);
    ListNode *p = &p1;
    while (p) {
        cout << p->val << "\t";
        p = p->next;
    }
}

void Sort::PrintSortAns(vector<int> &ans) {
    for (auto item : ans)
        cout << item << "\t";
    cout << endl;
}

void Sort::QuickSort4List(ListNode *head) {
    if (head == nullptr)
        return;
    stack<pair<ListNode *, ListNode *>> s;
    s.push(make_pair(head, nullptr)); // [low, high)
    while (!s.empty()) {
        ListNode *low = s.top().first;
        ListNode *high = s.top().second;
        s.pop();

        int key = low->val;
        // --smaller than key--P--bigger than key--
        ListNode *p = low;  // p->val is smaller than key
        ListNode *q = low->next; // cursor

        while (q != high) {
            if (q->val < key) {
                p = p->next; // p->val is smaller than key, so move forward
                swap(p->val, q->val); // swap a smaller val forward
            }
            q = q->next; // ++ cursor
        }
        swap(p->val, key);
        if (low != nullptr && (low != p))
            s.push(make_pair(low, p));
        if (p != nullptr && p->next != nullptr && p->next != high)
            s.push(make_pair(p->next, high));
    }
}
