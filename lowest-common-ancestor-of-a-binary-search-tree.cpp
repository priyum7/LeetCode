/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
​
class Solution {
public:
    
    
    pair<TreeNode*, pair<bool, bool>> helper(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(root==NULL)
        {
            return {NULL, {false,false}};
        }
        
        bool temp1=false, temp2=false;
        
        if(root == p)
        {
            cout<<"p found";
            temp1=true;
        }
        
        if(root == q)
        {
            cout<<"q found";
            temp2=true;
        }
        
        
        pair<TreeNode*, pair<bool, bool>> a = helper(root->left, p, q);
        
        if(a.second.first && a.second.second)
        {
            return a;
        }
        
        pair<TreeNode*, pair<bool, bool>> b = helper(root->right, p, q);
        
        if(b.second.first && b.second.second)
        {
            return b;
        }
        
        pair<TreeNode*, pair<bool, bool>> result = {NULL, {temp1||a.second.first||b.second.first, temp2||a.second.second||b.second.second}};
        
        if(result.second.first && result.second.second)
        {
            result.first=root;
            
        }
        
        return result;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return helper(root, p, q).first;
    }
};
