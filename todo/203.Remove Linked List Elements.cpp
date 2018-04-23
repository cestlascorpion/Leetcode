#include "000.config.h"

class Solution
{
  public:
    ListNode *removeElements(ListNode *head, int val)
    {
        if (head == nullptr)
            return nullptr;

        while (head->val == val)
        {
            head = head->next;
            if (head == nullptr)
                return nullptr;
        }

        ListNode *p = head;
        while (p->next != nullptr)
        {
            if (p->next->val == val)
                p->next = p->next->next;
            else
                p = p->next;
        }
        return head;
    }
};