#include "0. config.h"

class Solution
{
  public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int carry = 0;
        ListNode *h = new ListNode(0);
        ListNode *p = h;
        while (l1 != NULL || l2 != NULL || carry != 0)
        {
            int val1 = l1 == NULL ? 0 : l1->val;
            int val2 = l2 == NULL ? 0 : l2->val;
            int sum = carry + val1 + val2;
            p->next = new ListNode(sum % 10);
            p = p->next;
            carry = sum / 10;
            l1 = l1 == NULL ? NULL : l1->next;
            l2 = l2 == NULL ? NULL : l2->next;
        }
        return h->next;
    }
};