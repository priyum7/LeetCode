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
    
    
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode* left = head;
        
        ListNode* result = NULL;
        ListNode* prev = NULL;
        ListNode* end = NULL;
        
        int t=0;
        
        ListNode* temp = NULL;
        
        
        
        
        while(true)
        {
            if(t==0)
            {
                temp = new ListNode(left->val);
                end = temp;
                t++;
                left = left->next;
            }
            else if(t%k==0 || left==NULL)
            {
                ListNode* curr = left;
                end->next = left;
                
                
                if(left==NULL && t<k && result )
                {
                    break;
                }
                
                
                if(prev==NULL)
                {
                    result = temp;
                    prev = end;
                }
                else
                {
                    prev->next = temp;
                    prev= end;
                }
                
                
                if(left==NULL)
                {
                    break;
                }
                
                t=0;
                continue;
                
                
            }
            else
            {
                ListNode* x = new ListNode(left->val);
                x->next = temp;
                temp=x;
                t++;
                left = left->next;
                
            }
        }
        return result;
        
    }
};