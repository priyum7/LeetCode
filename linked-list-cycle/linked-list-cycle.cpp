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
    bool hasCycle(ListNode *head) {
        
        unordered_map<ListNode*, int> hash;
        
        ListNode* temp=  head;
        
        int i=0;
        while(temp!=NULL)
        {
            if(hash.count(temp))
            {
                return true;
            }
            
            hash[temp] = i++;
            temp = temp->next;
        }
        
        return false;
        
        
        
    }
};