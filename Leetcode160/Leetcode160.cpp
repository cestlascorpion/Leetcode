//
// Created by cestl on 2018/4/28 0028.
//

#include "Leetcode160.h"

ListNode *Leetcode160::getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (headA == nullptr || headB == nullptr)
        return nullptr;

    ListNode *cur1 = headA, *cur2 = headB;
    while (cur1 != cur2)
    {
        cur1 = cur1 ? cur1->next : headB;
        cur2 = cur2 ? cur2->next : headA;
    }
    return cur1;
}
