//
// Created by hans on 4/26/18.
//

#include "Leetcode21.h"

ListNode *Leetcode21::mergeTwoLists(ListNode *l1, ListNode *l2) {
    if (l1 == nullptr)
        return l2;
    if (l2 == nullptr)
        return l1;
    ListNode *ans = nullptr;
    if (l1->val < l2->val) {
        ans = l1;
        ans->next = mergeTwoLists(l1->next, l2);
    } else {
        ans = l2;
        ans->next = mergeTwoLists(l1, l2->next);
    }
    return ans;
}

void Leetcode21::test21() {
    ListNode p1(1);
    ListNode p2(2);
    ListNode p3(3);
    ListNode p4(4);
    ListNode p5(5);
    p1.next = &p2;
    p2.next = &p4;
    p3.next = &p5;
    ListNode *ans = mergeTwoLists(&p1, &p3);
    while (ans != nullptr) {
        cout << ans->val << " ";
        ans = ans->next;
    }
    cout << endl;
}
