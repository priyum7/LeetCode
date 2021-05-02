/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        
        unordered_map<Node*, Node*> mymap;
        
        Node* temp = head;
        
        while(temp)
        {
            mymap[temp] = new Node(temp->val);
            temp = temp->next;
        }
        
        
        temp = head;
        Node* newHead = mymap[temp];
        Node* newTemp = newHead;
        
        while(temp)
        {
            newTemp->next = mymap[temp->next];
            newTemp->random = mymap[temp->random];
            
            temp = temp->next;
            newTemp = newTemp->next;
            
        }
        
        return newHead;
        
    }
};