//
// Created by hans on 4/26/18.
//

#include "Leetcode141.h"

bool Leetcode141::hasCycle(ListNode *head) {
    if (head == nullptr)
        return false;
    ListNode *f = head->next;
    ListNode *s = head;
    while (f != nullptr && f->next != nullptr) {
        if (f == s)
            return true;
        f = f->next->next;
        s = s->next;
    }
    return false;
}

void Leetcode141::test141() {
    ListNode p0(0);
    ListNode p1(0);
    ListNode p2(0);
    ListNode p3(0);
    ListNode p4(0);
    ListNode p5(0);
    p1.next = &p2;
    p2.next = &p3;
    p3.next = &p4;
    p4.next = &p5;
    p5.next = &p1;
    cout << "hascycle == " << hasCycle(&p1) << endl;
}
