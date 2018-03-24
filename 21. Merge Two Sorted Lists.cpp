#include "0. config.h"

class Solution
{
  public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (l1 == NULL || l2 == NULL)
        {
            if (!l1)
                return l2;
            if (!l2)
                return l1;
        }

        ListNode *res = new ListNode(0);
        if (l1->val < l2->val)
        {
            res->val = l1->val;
            l1 = l1->next;
        }
        else
        {
            res->val = l2->val;
            l2 = l2->next;
        }
        res->next = mergeTwoLists(l1, l2);
        return res;
    }
};