/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* slow = head;
        ListNode* fast = head;
         ListNode* prev = NULL;
        
        for(int t=0;t<n;t++)
        {
            fast = fast->next;
        }
        while(fast)
        {
            fast = fast->next;
            prev = slow;
            slow = slow->next;
        }
        
        if(slow==head)
            head = head->next;
        else if(slow->next==NULL)
        {
            prev->next=NULL;
        }
        else
        {slow->val = slow->next->val;
        slow->next = slow->next->next;
        }
        
        return head;
        
        
    }
};