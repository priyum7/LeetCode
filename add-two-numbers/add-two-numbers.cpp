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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        queue<int> num1, num2;
        
        while(l1!=NULL)
        {
            num1.push(l1->val);
            l1 = l1->next;
        }
        
        while(l2!=NULL)
        {
            num2.push(l2->val);
            l2 = l2->next;
        }
        
        int carry =0;
        
        ListNode* temp=NULL;
        ListNode* result=NULL;
        
        while(num1.size() || num2.size() || carry)
        {
            int sum = 0;
            
            if(num1.size())
            {
             sum+=num1.front();
                num1.pop();
            }
            
            if(num2.size())
            {
             sum+=num2.front();
                num2.pop();
            }
            
            
            
            sum+=carry;
        
            carry=0;
            
            if(sum>9)
            {
                carry++;
                sum =sum%10;
            }
            
            if(temp==NULL)
            {
                temp = new ListNode(sum);
                result = temp;
            }
            else
            {
            
                temp->next = new ListNode(sum);
                temp = temp->next;
                
            }   
            
        }
        
        return result;
        
    }
};