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
​
class Solution {
public:
    Node* copyRandomList(Node* head) {
        
       
       Node* temp = head;
        unordered_map<Node*, Node*> newNodeMap;
        
        while(temp!=NULL)
        {
            newNodeMap[temp] = new Node(temp->val);
            temp = temp->next;
        }
        
        temp = head;
        
        while(temp!=NULL)
        {
            
            if(temp->next)
                newNodeMap[temp]->next = newNodeMap[temp->next];
            if(temp->random)
                newNodeMap[temp]->random = newNodeMap[temp->random];
            temp = temp->next;
                
        }
        
        return newNodeMap[head];
        
    }
};
