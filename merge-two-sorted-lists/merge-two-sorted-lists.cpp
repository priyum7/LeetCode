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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        ListNode* left = l1;
        ListNode* right = l2;
        
        ListNode* temp = NULL;
        ListNode* result= NULL;
        ListNode* curr= NULL;
        
        while(l1 || l2)
        {
            if(l1 &&( !l2 || l1->val < l2->val))
            {
                curr = l1;
                l1=l1->next;
            }
            else
            {
                curr = l2;
                l2=l2->next;
            }
            
            if(!result)
            {
                temp = curr;
                result = curr;
            }
            else
            {
                temp->next = curr;
                temp=temp->next;
                temp->next=NULL;
            }
        }
        return result;
    }
};