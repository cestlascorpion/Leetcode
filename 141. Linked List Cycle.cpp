/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL)
            return false;
        
        if(head->next == NULL)
            return false;
        
        ListNode *fast = head->next;
        ListNode *slow = head;
        while(fast != slow)
        {
            if(fast->next == NULL)
                return false;
            if(fast->next->next == NULL)
                return false;
            
            fast = fast->next->next;
            slow = slow->next;
        }
        return true;
    }
};
*/

class Solution
{
  public:
    bool hasCycle(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return false;
        }
        ListNode *slow = head;
        ListNode *fast = head->next->next;
        while (fast != NULL && fast->next != NULL)
        {
            if (slow == fast)
            {
                return true;
            }
            else
            {
                slow = slow->next;
                fast = fast->next->next;
            }
        }
        return false;
    }
};