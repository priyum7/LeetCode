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
        
        ListNode* temp = head;
        int size=0;
        
        while(temp!=NULL)
        {
            temp = temp->next;
            size++;
        }
        
        
        
        size = size-n-1;
        
        if(size==-1)
        {
            head = head->next;
        }
        else{
            int t=0;
            temp = head;
            while(t<size)
            {
                temp = temp->next;
                t++;
                
            }
            temp->next = temp->next->next;
        }
        return head;
        
        
        
        
    }
};