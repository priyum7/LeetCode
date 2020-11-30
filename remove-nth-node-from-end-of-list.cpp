/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
 
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        int size=0;
        
        if(head->next==NULL)
            return NULL;
        
        ListNode* temp = head;
        
        while(temp!=NULL)
        {
            temp = temp->next;
            size++;
        }
        
        n = size-n-1;
        
        
        if(n==-1)
        {
            head=head->next;
        }
        else
        {
            temp = head;
​
            int i=0;
            while(i<n)
            {
                temp = temp ->next;
                i++;
            }
​
            temp->next = temp->next->next;
        }
        return head;
    }
};
