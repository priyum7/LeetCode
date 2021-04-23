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
    ListNode* reverseList(ListNode* head) {
        
        ListNode *newHead = NULL;

        
        while(head!=NULL)
        {
            
                ListNode* temp = newHead;
                newHead = new ListNode(head->val);
                newHead->next = temp;
                
            head = head->next;
        }
        
        return newHead;
        
    }
};