/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    void inorder(TreeNode* root, vector<int> &traversal, unordered_map<int, TreeNode*> &mymap)
    {
        if(!root)
            return;
        
        inorder(root->left, traversal, mymap);
        traversal.push_back(root->val);
        mymap[root->val] = root;
        inorder(root->right, traversal, mymap);
    }
    
    
    void recoverTree(TreeNode* root) {
        
        vector<int> traversal;
        unordered_map<int, TreeNode*> mymap;
        
        inorder(root, traversal, mymap);
        
        int first=INT_MIN, second=INT_MIN;
        for(int t=1; t<traversal.size(); t++)
        {   
            if(traversal[t] < traversal[t-1])
            {
                if(first>INT_MIN)
                    second = traversal[t];
                if(first == INT_MIN)
                {
                    first = traversal[t-1];
                    second = traversal[t];
                }
            }                    
        }
        cout<<endl;
        cout<<first<<" "<<second<<endl;
        
        if(second == INT_MIN)
            second = traversal.back();
        
        swap(mymap[first]->val, mymap[second]->val);
        
    }
};