//
// Created by Wang on 2019/11/10.
//

#ifndef LEETCODE_LEETCODE148CN_H
#define LEETCODE_LEETCODE148CN_H

#include <config.h>

class Leetcode148cn {
public:
    ListNode *sortList(ListNode *head);

    ListNode *sortList2(ListNode *head);

    ListNode *sortList3(ListNode *head);

private:
    void quick_sort(ListNode *head, ListNode *tail);

    ListNode *helper(ListNode *head, ListNode *tail);

    ListNode *merge_sort(ListNode *head);

    ListNode* do_merge(ListNode* l, ListNode* r);
};

#endif // LEETCODE_LEETCODE148CN_H
