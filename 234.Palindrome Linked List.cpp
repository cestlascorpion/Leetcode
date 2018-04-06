#include "000.config.h"

class Solution
{
  public:
    ListNode *reverseList(ListNode *root)
    {
        if (root == NULL || root->next == NULL)
            return root;

        ListNode *cur = root;
        ListNode *nxt = root->next;
        root->next = NULL;
        while (nxt != NULL)
        {
            if (nxt->next == NULL)
            {
                nxt->next = cur;
                break;
            }
            else
            {
                ListNode *temp = nxt->next;
                nxt->next = cur;
                cur = nxt;
                nxt = temp;
            }
        }
        return nxt;
    }
    bool isPalindrome(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return true;
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        //循环结束后
        //链表长度为奇数：fast指向最后一个元素 slow指向正中间的元素
        //链表长度为偶数：fast指向最后一个元素的next，即NULL；slow指向正中间位置的后一个元素
        if (fast != NULL) //奇数情况
        {
            slow = slow->next;
        }
        //反转链表
        slow = reverseList(slow); //也可以在寻找中间位置的同时去反转前半段链表

        while (slow != NULL)
        {
            if (head->val != slow->val)
                return false;
            head = head->next;
            slow = slow->next;
        }
        return true;
    }
};
/*
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *fast = head, *slow = head;
        ListNode *prev = nullptr, *next;
        bool res = true;
        
        // reverse the first half
        while ( fast && fast->next ) {
            fast = fast->next->next;
            next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }
        
        fast = (fast == nullptr ) ? slow : slow->next;
        slow = prev;
        prev = next;
        
        while ( fast ) {
            // cout << fast->val << "," << slow->val << endl;
            if ( fast->val != slow->val )
                res = false;
            fast = fast->next;
            
            next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }
        return res;
    }
};
*/
