//
// Created by cestl on 2018/4/28 0028.
//

#include "Leetcode2.h"

ListNode *Leetcode2::addTwoNumbers(ListNode *l1, ListNode *l2) {
    if (l1 == nullptr && l2 == nullptr)
        return nullptr;

    int carry = 0;
    ListNode *ans = new ListNode(0);
    ListNode *p = ans;

    while (l1 || l2 || carry) {
        int v1 = 0;
        int v2 = 0;

        if (l1) {
            v1 = l1->val;
            l1 = l1->next;
        }
        if (l2) {
            v2 = l2->val;
            l2 = l2->next;
        }
        int sum = v1 + v2 + carry;
        p->next = new ListNode(sum % 10);
        carry = sum / 10;
        p = p->next;
    }
    p = ans;
    ans = ans->next;
    delete (p);
    return ans;
}

void Leetcode2::test2() {
    ListNode p1(2);
    ListNode p2(4);
    ListNode p3(3);
    ListNode p4(5);
    ListNode p5(6);
    ListNode p6(9);
    p1.next = &p2;
    p2.next = &p3;

    p4.next = &p5;
    p5.next = &p6;
    ListNode *p = addTwoNumbers(&p1, &p4);

    while (p) {
        cout << p->val << " " << endl;
        p = p->next;
    }
}
