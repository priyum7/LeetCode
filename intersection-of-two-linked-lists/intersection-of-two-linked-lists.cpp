/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        int s1=0, s2=0;
        ListNode* temp=NULL;
        
        temp = headA;
        while(temp)
        {
            s1++;
            temp = temp->next;
        }
        temp = headB;
        while(temp)
        {
            s2++;
            temp = temp->next;
        }
        
        
        int temp_size=0;
        
        if(s1>s2)
        {
            temp = headA;
            temp_size = s1-s2;
        }
        else
        {
            temp = headB;
            temp_size = s2-s1;
        }
        
        if(temp)
        {
            for(int t=0;t<temp_size;t++)
            {
                temp = temp->next;
            }
        }
        
        if(s1>s2)
        {
            headA=temp;
        }
        else
        {
            headB=temp;
        }
        
        while(headA && headB)
        {
            if(headA==headB)
                return headB;
            headA = headA -> next;
            headB = headB -> next;
        }
        return NULL;
        
        
    }
};