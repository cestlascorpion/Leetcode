//
// Created by cestl on 2018/4/28 0028.
//

#include "Leetcode328.h"

ListNode *Leetcode328::oddEvenList(ListNode *head) {
    if (head == nullptr)
        return nullptr;

    ListNode *p = head;
    ListNode *odd = new ListNode(0);
    ListNode *even = new ListNode(0);
    ListNode *p1 = odd;
    ListNode *p2 = even;
    bool flag = true;
    while (p) {
        if (flag) {
            p1->next = new ListNode(p->val);
            p1 = p1->next;
            flag = false;
        } else {
            p2->next = new ListNode(p->val);
            p2 = p2->next;
            flag = true;
        }
        p = p->next;
    }
    ListNode *ans = odd->next;
    delete odd;
    p1->next = even->next;
    delete even;
    return ans;
}

ListNode *Leetcode328::oddEvenList2(ListNode *head) {
    if (head == nullptr || head->next == nullptr)
        return head;
    ListNode *odd = head;
    ListNode *even = head->next;
    ListNode *add = head->next;
    while (odd->next && even->next) {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = add;
    return head;
}

void Leetcode328::test328() {
    ListNode p1(1);
    ListNode p2(2);
    ListNode p3(3);
    ListNode p4(4);
    ListNode p5(5);
    //ListNode p6(6);

    p1.next = &p2;
    p2.next = &p3;
    p3.next = &p4;
    p4.next = &p5;
    //p5.next = &p6;

    ListNode *ans = oddEvenList2(&p1);
    while (ans) {
        cout << ans->val << endl;
        ans = ans->next;
    }
}
