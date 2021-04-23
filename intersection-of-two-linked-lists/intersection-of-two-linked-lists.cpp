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
        
        unordered_map<ListNode*, int> hash;
        
        ListNode* temp = headA;
        
        while(temp!=NULL)
        {
            hash[temp]++;
            temp = temp->next;
        }
        
        temp = headB;
        
        while(temp!=NULL)
        {
            if(hash.count(temp))
            {
                break;
            }
            temp = temp->next;
        }
        
        return temp;
    }
};