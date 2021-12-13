/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    
    void helper(vector<int> &result, Node* root)
    {
        if(root==NULL)
        {
            return;
        }
        
        for(int t=0;t<root->children.size();t++)
        {
            helper(result, root->children[t]);    
        }
        
        result.push_back(root->val);
        
        
    }
    
    vector<int> postorder(Node* root) {
        
        vector<int> result;
        helper(result, root);
        return result;
        
    }
};