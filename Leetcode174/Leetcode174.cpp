//
// Created by hans on 4/26/18.
//

#include "Leetcode174.h"

ListNode *Leetcode174::removeNthFromEnd(ListNode *head, int n) {
    if (head == nullptr)
        return nullptr;
    ListNode *f = head;
    ListNode *s = head;
    for (int i = 0; i < n; ++i)
        f = f->next;
    // 1 2 3 4 5 6 7 nil
    // *   *     ^
    ListNode *p = nullptr;
    while (f != nullptr) {
        f = f->next;
        p = s;
        s = s->next;
    }
    // 1 2 3 4 5 6 7 nil
    //           * ^ *
    if (p == nullptr) {
        head = head->next;
    } else {
        p->next = s->next;
    }

    return head;
}

void Leetcode174::test174() {
    ListNode *head = new ListNode(0);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    cout << head->val << endl;
    ListNode *ans = removeNthFromEnd(head, 3);
    while (ans != nullptr) {
        cout << ans->val<<" ";
        ans = ans->next;
    }
}
